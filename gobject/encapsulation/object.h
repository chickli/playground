/*
 * object.h
 *
 *  Created on: Aug 5, 2018
 *      Author: cli
 */

#ifndef ENCAPSULATION_OBJECT_H_
#define ENCAPSULATION_OBJECT_H_

#include "glib.h"
#include "glib-object.h"

typedef struct _MiniObjectPrivate MiniObjectPrivate;

struct _MiniObject {
	GObject parent;

	/* public members can be defined in the header directly */
	gint id;

	/* private members reside in an opaque structure and will be defined in c file */
	MiniObjectPrivate* priv;


};
typedef struct _MiniObject MiniObject;

/* public member function declaration is exactly the same as C extern API except that
 * an Object pointer has to serve as the first parameter, corresponding to "this" in
 * c++ */
void main_miniobject_do_something(MiniObject* object);

struct _MiniObjectClass {
	GObjectClass parent_class;

	void (*do_something) (MiniObject*self);
};

typedef struct _MiniObjectClass MiniObjectClass;

#define MINIOBJECT_TYPE() \
		main_miniobject_get_type()

#define MINIOBJECT_GET_CLASS(obj) \
		  (G_TYPE_INSTANCE_GET_CLASS((obj),MINIOBJECT_TYPE(),MiniObjectClass))

GType main_miniobject_get_type();



#endif /* ENCAPSULATION_OBJECT_H_ */
