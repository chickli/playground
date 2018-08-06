/*
 * object.c
 *
 *  Created on: Aug 5, 2018
 *      Author: cli
 */

#include "object.h"

typedef struct _MiniObjectPrivate {
	gint bar;
} MiniObjectPrivate;

static void main_miniobject_class_init(MiniObjectClass* class);
static void main_miniobject_init(MiniObject* self);

G_DEFINE_TYPE_WITH_PRIVATE(MiniObject, main_miniobject, G_TYPE_OBJECT);

/*
 * implementation of public method main_miniobject_do_something
 * */
void main_miniobject_do_something(MiniObject* self) {
	MiniObjectClass *kclass = MINIOBJECT_GET_CLASS(self);
	if (kclass->do_something) {
		/* In this way we're calling the corresponding method in class object, which means
		 * this method is virtual */
		kclass->do_something(self);
	}

	/* for non-virtual method we can put what ever it should be here for implementation,
	 * which works on current type only and can't be overridden */
}

/*
 * default implementation of a virtual method in this class, can be overridden by derived classes
 * */
static void main_miniobject_do_something_default(MiniObject*self) {
	printf("Hello\n");

	printf("id = %d, bar = %d\n", self->id, self->priv->bar);
}

/**
 * class initialization function is responsible for initializing class wide variables, notably the
 * virtual table.
 * Overridden of methods in parent class can only be done here
 *
 * GObject also allows class specific properties be registered here (beyond the scope of OO)
 */
static void main_miniobject_class_init(MiniObjectClass* class) {
	class->do_something = main_miniobject_do_something_default; /*< register the default virtual method */
}

/**
 * object initialization function is similar to construct, responsible for initializing members for
 * a specific instance in a generic way
 */
static void main_miniobject_init(MiniObject* self) {
	self->id = -1;

	self->priv = main_miniobject_get_instance_private(self);
	self->priv->bar = -1;
}


int main(int argc, char** argv) {
	GType type = main_miniobject_get_type();

	MiniObject* obj = g_object_new(type, NULL);

	if (obj) {
		main_miniobject_do_something(obj);
	}

	g_object_unref(obj);

	return 0;
}



