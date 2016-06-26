/* Logger.c generated by valac 0.32.1, the Vala compiler
 * generated from Logger.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define TYPE_LOGGER (logger_get_type ())
#define LOGGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_LOGGER, Logger))
#define LOGGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_LOGGER, LoggerClass))
#define IS_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_LOGGER))
#define IS_LOGGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_LOGGER))
#define LOGGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_LOGGER, LoggerClass))

typedef struct _Logger Logger;
typedef struct _LoggerClass LoggerClass;
typedef struct _LoggerPrivate LoggerPrivate;
#define _logger_unref0(var) ((var == NULL) ? NULL : (var = (logger_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _ParamSpecLogger ParamSpecLogger;

struct _Logger {
	GTypeInstance parent_instance;
	volatile int ref_count;
	LoggerPrivate * priv;
};

struct _LoggerClass {
	GTypeClass parent_class;
	void (*finalize) (Logger *self);
};

struct _ParamSpecLogger {
	GParamSpec parent_instance;
};


static gpointer logger_parent_class = NULL;
static Logger* logger__instance;
static Logger* logger__instance = NULL;

gpointer logger_ref (gpointer instance);
void logger_unref (gpointer instance);
GParamSpec* param_spec_logger (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_logger (GValue* value, gpointer v_object);
void value_take_logger (GValue* value, gpointer v_object);
gpointer value_get_logger (const GValue* value);
GType logger_get_type (void) G_GNUC_CONST;
enum  {
	LOGGER_DUMMY_PROPERTY
};
static Logger* logger_new (void);
static Logger* logger_construct (GType object_type);
Logger* logger_GetInstance (void);
void logger_Info (Logger* self, const gchar* message);
void logger_Error (Logger* self, GError* e);
static void logger_finalize (Logger* obj);


static Logger* logger_construct (GType object_type) {
	Logger* self = NULL;
	self = (Logger*) g_type_create_instance (object_type);
	return self;
}


static Logger* logger_new (void) {
	return logger_construct (TYPE_LOGGER);
}


static gpointer _logger_ref0 (gpointer self) {
	return self ? logger_ref (self) : NULL;
}


Logger* logger_GetInstance (void) {
	Logger* result = NULL;
	Logger* _tmp0_ = NULL;
	Logger* _tmp2_ = NULL;
	Logger* _tmp3_ = NULL;
	_tmp0_ = logger__instance;
	if (_tmp0_ == NULL) {
		Logger* _tmp1_ = NULL;
		_tmp1_ = logger_new ();
		_logger_unref0 (logger__instance);
		logger__instance = _tmp1_;
	}
	_tmp2_ = logger__instance;
	_tmp3_ = _logger_ref0 (_tmp2_);
	result = _tmp3_;
	return result;
}


void logger_Info (Logger* self, const gchar* message) {
	FILE* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (message != NULL);
	_tmp0_ = stderr;
	_tmp1_ = message;
	_tmp2_ = g_strconcat (_tmp1_, "\n", NULL);
	_tmp3_ = _tmp2_;
	fprintf (_tmp0_, "%s", _tmp3_);
	_g_free0 (_tmp3_);
}


void logger_Error (Logger* self, GError* e) {
	FILE* _tmp0_ = NULL;
	GError* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = stderr;
	_tmp1_ = e;
	_tmp2_ = _tmp1_->message;
	_tmp3_ = g_strconcat (_tmp2_, "\n", NULL);
	_tmp4_ = _tmp3_;
	fprintf (_tmp0_, "%s", _tmp4_);
	_g_free0 (_tmp4_);
}


static void value_logger_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_logger_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		logger_unref (value->data[0].v_pointer);
	}
}


static void value_logger_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = logger_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_logger_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_logger_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		Logger* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = logger_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_logger_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	Logger** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = logger_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_logger (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecLogger* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_LOGGER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_logger (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_LOGGER), NULL);
	return value->data[0].v_pointer;
}


void value_set_logger (GValue* value, gpointer v_object) {
	Logger* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_LOGGER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_LOGGER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		logger_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		logger_unref (old);
	}
}


void value_take_logger (GValue* value, gpointer v_object) {
	Logger* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_LOGGER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_LOGGER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		logger_unref (old);
	}
}


static void logger_class_init (LoggerClass * klass) {
	logger_parent_class = g_type_class_peek_parent (klass);
	((LoggerClass *) klass)->finalize = logger_finalize;
}


static void logger_instance_init (Logger * self) {
	self->ref_count = 1;
}


static void logger_finalize (Logger* obj) {
	Logger * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_LOGGER, Logger);
	g_signal_handlers_destroy (self);
}


GType logger_get_type (void) {
	static volatile gsize logger_type_id__volatile = 0;
	if (g_once_init_enter (&logger_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_logger_init, value_logger_free_value, value_logger_copy_value, value_logger_peek_pointer, "p", value_logger_collect_value, "p", value_logger_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (LoggerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) logger_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Logger), 0, (GInstanceInitFunc) logger_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType logger_type_id;
		logger_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Logger", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&logger_type_id__volatile, logger_type_id);
	}
	return logger_type_id__volatile;
}


gpointer logger_ref (gpointer instance) {
	Logger* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void logger_unref (gpointer instance) {
	Logger* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		LOGGER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



