/* BinaryTypes.c generated by valac 0.30.1, the Vala compiler
 * generated from BinaryTypes.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <gobject/gvaluecollector.h>


#define TYPE_BINARY_TYPE (binary_type_get_type ())
#define BINARY_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BINARY_TYPE, BinaryType))
#define BINARY_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BINARY_TYPE, BinaryTypeClass))
#define IS_BINARY_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BINARY_TYPE))
#define IS_BINARY_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BINARY_TYPE))
#define BINARY_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BINARY_TYPE, BinaryTypeClass))

typedef struct _BinaryType BinaryType;
typedef struct _BinaryTypeClass BinaryTypeClass;
typedef struct _BinaryTypePrivate BinaryTypePrivate;
typedef struct _ParamSpecBinaryType ParamSpecBinaryType;

#define TYPE_BINARY_NUMBER (binary_number_get_type ())
#define BINARY_NUMBER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BINARY_NUMBER, BinaryNumber))
#define BINARY_NUMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BINARY_NUMBER, BinaryNumberClass))
#define IS_BINARY_NUMBER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BINARY_NUMBER))
#define IS_BINARY_NUMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BINARY_NUMBER))
#define BINARY_NUMBER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BINARY_NUMBER, BinaryNumberClass))

typedef struct _BinaryNumber BinaryNumber;
typedef struct _BinaryNumberClass BinaryNumberClass;
typedef struct _BinaryNumberPrivate BinaryNumberPrivate;

#define TYPE_BINARY_ARRAY (binary_array_get_type ())
#define BINARY_ARRAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BINARY_ARRAY, BinaryArray))
#define BINARY_ARRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BINARY_ARRAY, BinaryArrayClass))
#define IS_BINARY_ARRAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BINARY_ARRAY))
#define IS_BINARY_ARRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BINARY_ARRAY))
#define BINARY_ARRAY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BINARY_ARRAY, BinaryArrayClass))

typedef struct _BinaryArray BinaryArray;
typedef struct _BinaryArrayClass BinaryArrayClass;
typedef struct _BinaryArrayPrivate BinaryArrayPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_BINARY_BYTES (binary_bytes_get_type ())
#define BINARY_BYTES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BINARY_BYTES, BinaryBytes))
#define BINARY_BYTES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BINARY_BYTES, BinaryBytesClass))
#define IS_BINARY_BYTES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BINARY_BYTES))
#define IS_BINARY_BYTES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BINARY_BYTES))
#define BINARY_BYTES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BINARY_BYTES, BinaryBytesClass))

typedef struct _BinaryBytes BinaryBytes;
typedef struct _BinaryBytesClass BinaryBytesClass;
typedef struct _BinaryBytesPrivate BinaryBytesPrivate;

#define TYPE_BINARY_U8 (binary_u8_get_type ())
#define BINARY_U8(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BINARY_U8, BinaryU8))
#define BINARY_U8_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BINARY_U8, BinaryU8Class))
#define IS_BINARY_U8(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BINARY_U8))
#define IS_BINARY_U8_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BINARY_U8))
#define BINARY_U8_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BINARY_U8, BinaryU8Class))

typedef struct _BinaryU8 BinaryU8;
typedef struct _BinaryU8Class BinaryU8Class;
typedef struct _BinaryU8Private BinaryU8Private;

struct _BinaryType {
	GTypeInstance parent_instance;
	volatile int ref_count;
	BinaryTypePrivate * priv;
};

struct _BinaryTypeClass {
	GTypeClass parent_class;
	void (*finalize) (BinaryType *self);
};

struct _ParamSpecBinaryType {
	GParamSpec parent_instance;
};

struct _BinaryNumber {
	BinaryType parent_instance;
	BinaryNumberPrivate * priv;
};

struct _BinaryNumberClass {
	BinaryTypeClass parent_class;
	gint (*AsInt32) (BinaryNumber* self);
};

struct _BinaryArray {
	BinaryType parent_instance;
	BinaryArrayPrivate * priv;
};

struct _BinaryArrayClass {
	BinaryTypeClass parent_class;
};

struct _BinaryArrayPrivate {
	GeeArrayList* _data;
};

struct _BinaryBytes {
	BinaryType parent_instance;
	BinaryBytesPrivate * priv;
};

struct _BinaryBytesClass {
	BinaryTypeClass parent_class;
};

struct _BinaryBytesPrivate {
	guint8* _data;
	gint _data_length1;
	gint __data_size_;
};

struct _BinaryU8 {
	BinaryNumber parent_instance;
	BinaryU8Private * priv;
};

struct _BinaryU8Class {
	BinaryNumberClass parent_class;
};

struct _BinaryU8Private {
	guint8 _data;
};


static gpointer binary_type_parent_class = NULL;
static gpointer binary_number_parent_class = NULL;
static gpointer binary_array_parent_class = NULL;
static gpointer binary_bytes_parent_class = NULL;
static gpointer binary_u8_parent_class = NULL;

gpointer binary_type_ref (gpointer instance);
void binary_type_unref (gpointer instance);
GParamSpec* param_spec_binary_type (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_binary_type (GValue* value, gpointer v_object);
void value_take_binary_type (GValue* value, gpointer v_object);
gpointer value_get_binary_type (const GValue* value);
GType binary_type_get_type (void) G_GNUC_CONST;
enum  {
	BINARY_TYPE_DUMMY_PROPERTY
};
#define BINARY_TYPE_BYTES_TYPE ((guint8) 1)
#define BINARY_TYPE_U8_TYPE ((guint8) 2)
BinaryType* binary_type_construct (GType object_type);
static void binary_type_finalize (BinaryType* obj);
GType binary_number_get_type (void) G_GNUC_CONST;
enum  {
	BINARY_NUMBER_DUMMY_PROPERTY
};
gint binary_number_AsInt32 (BinaryNumber* self);
static gint binary_number_real_AsInt32 (BinaryNumber* self);
BinaryNumber* binary_number_construct (GType object_type);
GType binary_array_get_type (void) G_GNUC_CONST;
#define BINARY_ARRAY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_BINARY_ARRAY, BinaryArrayPrivate))
enum  {
	BINARY_ARRAY_DUMMY_PROPERTY
};
BinaryArray* binary_array_new (void);
BinaryArray* binary_array_construct (GType object_type);
void binary_array_Add (BinaryArray* self, BinaryType* data);
BinaryType* binary_array_Get (BinaryArray* self, gint index);
static void binary_array_finalize (BinaryType* obj);
GType binary_bytes_get_type (void) G_GNUC_CONST;
#define BINARY_BYTES_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_BINARY_BYTES, BinaryBytesPrivate))
enum  {
	BINARY_BYTES_DUMMY_PROPERTY
};
BinaryBytes* binary_bytes_new (void);
BinaryBytes* binary_bytes_construct (GType object_type);
BinaryBytes* binary_bytes_new_WithArray (guint8* data, int data_length1);
BinaryBytes* binary_bytes_construct_WithArray (GType object_type, guint8* data, int data_length1);
void binary_bytes_Set (BinaryBytes* self, guint8* data, int data_length1);
static guint8* _vala_array_dup5 (guint8* self, int length);
guint8* binary_bytes_Get (BinaryBytes* self, int* result_length1);
static guint8* _vala_array_dup6 (guint8* self, int length);
static void binary_bytes_finalize (BinaryType* obj);
GType binary_u8_get_type (void) G_GNUC_CONST;
#define BINARY_U8_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_BINARY_U8, BinaryU8Private))
enum  {
	BINARY_U8_DUMMY_PROPERTY
};
BinaryU8* binary_u8_new (void);
BinaryU8* binary_u8_construct (GType object_type);
BinaryU8* binary_u8_new_WithU8 (guint8 data);
BinaryU8* binary_u8_construct_WithU8 (GType object_type, guint8 data);
void binary_u8_Set (BinaryU8* self, guint8 data);
guint8 binary_u8_Get (BinaryU8* self);
static gint binary_u8_real_AsInt32 (BinaryNumber* base);
static void binary_u8_finalize (BinaryType* obj);


BinaryType* binary_type_construct (GType object_type) {
	BinaryType* self = NULL;
	self = (BinaryType*) g_type_create_instance (object_type);
	return self;
}


static void value_binary_type_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_binary_type_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		binary_type_unref (value->data[0].v_pointer);
	}
}


static void value_binary_type_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = binary_type_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_binary_type_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_binary_type_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		BinaryType* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = binary_type_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_binary_type_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	BinaryType** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = binary_type_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_binary_type (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecBinaryType* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_BINARY_TYPE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_binary_type (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_BINARY_TYPE), NULL);
	return value->data[0].v_pointer;
}


void value_set_binary_type (GValue* value, gpointer v_object) {
	BinaryType* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_BINARY_TYPE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_BINARY_TYPE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		binary_type_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		binary_type_unref (old);
	}
}


void value_take_binary_type (GValue* value, gpointer v_object) {
	BinaryType* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_BINARY_TYPE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_BINARY_TYPE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		binary_type_unref (old);
	}
}


static void binary_type_class_init (BinaryTypeClass * klass) {
	binary_type_parent_class = g_type_class_peek_parent (klass);
	((BinaryTypeClass *) klass)->finalize = binary_type_finalize;
}


static void binary_type_instance_init (BinaryType * self) {
	self->ref_count = 1;
}


static void binary_type_finalize (BinaryType* obj) {
	BinaryType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_BINARY_TYPE, BinaryType);
	g_signal_handlers_destroy (self);
}


GType binary_type_get_type (void) {
	static volatile gsize binary_type_type_id__volatile = 0;
	if (g_once_init_enter (&binary_type_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_binary_type_init, value_binary_type_free_value, value_binary_type_copy_value, value_binary_type_peek_pointer, "p", value_binary_type_collect_value, "p", value_binary_type_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (BinaryTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) binary_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BinaryType), 0, (GInstanceInitFunc) binary_type_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType binary_type_type_id;
		binary_type_type_id = g_type_register_fundamental (g_type_fundamental_next (), "BinaryType", &g_define_type_info, &g_define_type_fundamental_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&binary_type_type_id__volatile, binary_type_type_id);
	}
	return binary_type_type_id__volatile;
}


gpointer binary_type_ref (gpointer instance) {
	BinaryType* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void binary_type_unref (gpointer instance) {
	BinaryType* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		BINARY_TYPE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static gint binary_number_real_AsInt32 (BinaryNumber* self) {
	g_critical ("Type `%s' does not implement abstract method `binary_number_AsInt32'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0;
}


gint binary_number_AsInt32 (BinaryNumber* self) {
	g_return_val_if_fail (self != NULL, 0);
	return BINARY_NUMBER_GET_CLASS (self)->AsInt32 (self);
}


BinaryNumber* binary_number_construct (GType object_type) {
	BinaryNumber* self = NULL;
	self = (BinaryNumber*) binary_type_construct (object_type);
	return self;
}


static void binary_number_class_init (BinaryNumberClass * klass) {
	binary_number_parent_class = g_type_class_peek_parent (klass);
	((BinaryNumberClass *) klass)->AsInt32 = binary_number_real_AsInt32;
}


static void binary_number_instance_init (BinaryNumber * self) {
}


GType binary_number_get_type (void) {
	static volatile gsize binary_number_type_id__volatile = 0;
	if (g_once_init_enter (&binary_number_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (BinaryNumberClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) binary_number_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BinaryNumber), 0, (GInstanceInitFunc) binary_number_instance_init, NULL };
		GType binary_number_type_id;
		binary_number_type_id = g_type_register_static (TYPE_BINARY_TYPE, "BinaryNumber", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&binary_number_type_id__volatile, binary_number_type_id);
	}
	return binary_number_type_id__volatile;
}


BinaryArray* binary_array_construct (GType object_type) {
	BinaryArray* self = NULL;
	GeeArrayList* _tmp0_ = NULL;
	self = (BinaryArray*) binary_type_construct (object_type);
	_tmp0_ = gee_array_list_new (TYPE_BINARY_TYPE, (GBoxedCopyFunc) binary_type_ref, binary_type_unref, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->_data);
	self->priv->_data = _tmp0_;
	return self;
}


BinaryArray* binary_array_new (void) {
	return binary_array_construct (TYPE_BINARY_ARRAY);
}


void binary_array_Add (BinaryArray* self, BinaryType* data) {
	GeeArrayList* _tmp0_ = NULL;
	BinaryType* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (data != NULL);
	_tmp0_ = self->priv->_data;
	_tmp1_ = data;
	gee_abstract_collection_add ((GeeAbstractCollection*) _tmp0_, _tmp1_);
}


BinaryType* binary_array_Get (BinaryArray* self, gint index) {
	BinaryType* result = NULL;
	GeeArrayList* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gpointer _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data;
	_tmp1_ = index;
	_tmp2_ = gee_abstract_list_get ((GeeAbstractList*) _tmp0_, _tmp1_);
	result = (BinaryType*) _tmp2_;
	return result;
}


static void binary_array_class_init (BinaryArrayClass * klass) {
	binary_array_parent_class = g_type_class_peek_parent (klass);
	((BinaryTypeClass *) klass)->finalize = binary_array_finalize;
	g_type_class_add_private (klass, sizeof (BinaryArrayPrivate));
}


static void binary_array_instance_init (BinaryArray * self) {
	self->priv = BINARY_ARRAY_GET_PRIVATE (self);
}


static void binary_array_finalize (BinaryType* obj) {
	BinaryArray * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_BINARY_ARRAY, BinaryArray);
	_g_object_unref0 (self->priv->_data);
	BINARY_TYPE_CLASS (binary_array_parent_class)->finalize (obj);
}


GType binary_array_get_type (void) {
	static volatile gsize binary_array_type_id__volatile = 0;
	if (g_once_init_enter (&binary_array_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (BinaryArrayClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) binary_array_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BinaryArray), 0, (GInstanceInitFunc) binary_array_instance_init, NULL };
		GType binary_array_type_id;
		binary_array_type_id = g_type_register_static (TYPE_BINARY_TYPE, "BinaryArray", &g_define_type_info, 0);
		g_once_init_leave (&binary_array_type_id__volatile, binary_array_type_id);
	}
	return binary_array_type_id__volatile;
}


BinaryBytes* binary_bytes_construct (GType object_type) {
	BinaryBytes* self = NULL;
	self = (BinaryBytes*) binary_type_construct (object_type);
	return self;
}


BinaryBytes* binary_bytes_new (void) {
	return binary_bytes_construct (TYPE_BINARY_BYTES);
}


BinaryBytes* binary_bytes_construct_WithArray (GType object_type, guint8* data, int data_length1) {
	BinaryBytes* self = NULL;
	guint8* _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	self = (BinaryBytes*) binary_type_construct (object_type);
	_tmp0_ = data;
	_tmp0__length1 = data_length1;
	binary_bytes_Set (self, _tmp0_, _tmp0__length1);
	return self;
}


BinaryBytes* binary_bytes_new_WithArray (guint8* data, int data_length1) {
	return binary_bytes_construct_WithArray (TYPE_BINARY_BYTES, data, data_length1);
}


static guint8* _vala_array_dup5 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


void binary_bytes_Set (BinaryBytes* self, guint8* data, int data_length1) {
	guint8* _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	guint8* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = data;
	_tmp0__length1 = data_length1;
	_tmp1_ = (_tmp0_ != NULL) ? _vala_array_dup5 (_tmp0_, _tmp0__length1) : ((gpointer) _tmp0_);
	_tmp1__length1 = _tmp0__length1;
	self->priv->_data = (g_free (self->priv->_data), NULL);
	self->priv->_data = _tmp1_;
	self->priv->_data_length1 = _tmp1__length1;
	self->priv->__data_size_ = self->priv->_data_length1;
}


static guint8* _vala_array_dup6 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


guint8* binary_bytes_Get (BinaryBytes* self, int* result_length1) {
	guint8* result = NULL;
	guint8* _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	guint8* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	guint8* _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data;
	_tmp0__length1 = self->priv->_data_length1;
	_tmp1_ = (_tmp0_ != NULL) ? _vala_array_dup6 (_tmp0_, _tmp0__length1) : ((gpointer) _tmp0_);
	_tmp1__length1 = _tmp0__length1;
	_tmp2_ = _tmp1_;
	_tmp2__length1 = _tmp1__length1;
	if (result_length1) {
		*result_length1 = _tmp2__length1;
	}
	result = _tmp2_;
	return result;
}


static void binary_bytes_class_init (BinaryBytesClass * klass) {
	binary_bytes_parent_class = g_type_class_peek_parent (klass);
	((BinaryTypeClass *) klass)->finalize = binary_bytes_finalize;
	g_type_class_add_private (klass, sizeof (BinaryBytesPrivate));
}


static void binary_bytes_instance_init (BinaryBytes * self) {
	self->priv = BINARY_BYTES_GET_PRIVATE (self);
}


static void binary_bytes_finalize (BinaryType* obj) {
	BinaryBytes * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_BINARY_BYTES, BinaryBytes);
	self->priv->_data = (g_free (self->priv->_data), NULL);
	BINARY_TYPE_CLASS (binary_bytes_parent_class)->finalize (obj);
}


GType binary_bytes_get_type (void) {
	static volatile gsize binary_bytes_type_id__volatile = 0;
	if (g_once_init_enter (&binary_bytes_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (BinaryBytesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) binary_bytes_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BinaryBytes), 0, (GInstanceInitFunc) binary_bytes_instance_init, NULL };
		GType binary_bytes_type_id;
		binary_bytes_type_id = g_type_register_static (TYPE_BINARY_TYPE, "BinaryBytes", &g_define_type_info, 0);
		g_once_init_leave (&binary_bytes_type_id__volatile, binary_bytes_type_id);
	}
	return binary_bytes_type_id__volatile;
}


BinaryU8* binary_u8_construct (GType object_type) {
	BinaryU8* self = NULL;
	self = (BinaryU8*) binary_number_construct (object_type);
	return self;
}


BinaryU8* binary_u8_new (void) {
	return binary_u8_construct (TYPE_BINARY_U8);
}


BinaryU8* binary_u8_construct_WithU8 (GType object_type, guint8 data) {
	BinaryU8* self = NULL;
	guint8 _tmp0_ = 0U;
	self = (BinaryU8*) binary_number_construct (object_type);
	_tmp0_ = data;
	binary_u8_Set (self, _tmp0_);
	return self;
}


BinaryU8* binary_u8_new_WithU8 (guint8 data) {
	return binary_u8_construct_WithU8 (TYPE_BINARY_U8, data);
}


void binary_u8_Set (BinaryU8* self, guint8 data) {
	guint8 _tmp0_ = 0U;
	g_return_if_fail (self != NULL);
	_tmp0_ = data;
	self->priv->_data = _tmp0_;
}


guint8 binary_u8_Get (BinaryU8* self) {
	guint8 result = 0U;
	guint8 _tmp0_ = 0U;
	g_return_val_if_fail (self != NULL, 0U);
	_tmp0_ = self->priv->_data;
	result = _tmp0_;
	return result;
}


static gint binary_u8_real_AsInt32 (BinaryNumber* base) {
	BinaryU8 * self;
	gint result = 0;
	guint8 _tmp0_ = 0U;
	self = (BinaryU8*) base;
	_tmp0_ = self->priv->_data;
	result = (gint) _tmp0_;
	return result;
}


static void binary_u8_class_init (BinaryU8Class * klass) {
	binary_u8_parent_class = g_type_class_peek_parent (klass);
	((BinaryTypeClass *) klass)->finalize = binary_u8_finalize;
	g_type_class_add_private (klass, sizeof (BinaryU8Private));
	((BinaryNumberClass *) klass)->AsInt32 = binary_u8_real_AsInt32;
}


static void binary_u8_instance_init (BinaryU8 * self) {
	self->priv = BINARY_U8_GET_PRIVATE (self);
}


static void binary_u8_finalize (BinaryType* obj) {
	BinaryU8 * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_BINARY_U8, BinaryU8);
	BINARY_TYPE_CLASS (binary_u8_parent_class)->finalize (obj);
}


GType binary_u8_get_type (void) {
	static volatile gsize binary_u8_type_id__volatile = 0;
	if (g_once_init_enter (&binary_u8_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (BinaryU8Class), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) binary_u8_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BinaryU8), 0, (GInstanceInitFunc) binary_u8_instance_init, NULL };
		GType binary_u8_type_id;
		binary_u8_type_id = g_type_register_static (TYPE_BINARY_NUMBER, "BinaryU8", &g_define_type_info, 0);
		g_once_init_leave (&binary_u8_type_id__volatile, binary_u8_type_id);
	}
	return binary_u8_type_id__volatile;
}


