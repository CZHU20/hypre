/*
 * File:          SIDL_BaseClass_Module.h
 * Symbol:        SIDL.BaseClass-v0.8.2
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * Release:       $Name$
 * Revision:      @(#) $Id$
 * Description:   expose a constructor for the Python wrapper
 * 
 * Copyright (c) 2000-2002, The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have recieved a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 * babel-version = 0.8.2
 */

/*
 * THIS CODE IS AUTOMATICALLY GENERATED BY THE BABEL
 * COMPILER. DO NOT EDIT THIS!
 * 
 * External clients need an entry point to wrap a pointer
 * to an instance of SIDL.BaseClass.
 * This header files defines two methods that such clients
 * will need.
 *     SIDL_BaseClass__import
 *         This should be called in the client's init
 *         module method.
 *     SIDL_BaseClass__wrap
 *         This will wrap an IOR in a Python object.
 */

#ifndef included_SIDL_BaseClass_MODULE
#define included_SIDL_BaseClass_MODULE

#include "babel_config.h"
#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Forward declaration of IOR structure */
struct SIDL_BaseClass__object;
struct SIDL_BaseClass__array;

#define SIDL_BaseClass__wrap_NUM 0
#define SIDL_BaseClass__wrap_RETURN PyObject *
#define SIDL_BaseClass__wrap_PROTO (struct SIDL_BaseClass__object *sidlobj)

#define SIDL_BaseClass__convert_NUM 1
#define SIDL_BaseClass__convert_RETURN int
#define SIDL_BaseClass__convert_PROTO (PyObject *obj, struct SIDL_BaseClass__object **sidlobj)

#define SIDL_BaseClass__convert_python_array_NUM 2
#define SIDL_BaseClass__convert_python_array_RETURN int
#define SIDL_BaseClass__convert_python_array_PROTO (PyObject *obj, struct SIDL_BaseClass__array **sidlarray)

#define SIDL_BaseClass__convert_sidl_array_NUM 3
#define SIDL_BaseClass__convert_sidl_array_RETURN PyObject *
#define SIDL_BaseClass__convert_sidl_array_PROTO (struct SIDL_BaseClass__array *sidlarray)

#define SIDL_BaseClass__destroy_sidl_array_NUM 4
#define SIDL_BaseClass__destroy_sidl_array_RETURN void
#define SIDL_BaseClass__destroy_sidl_array_PROTO (struct SIDL_BaseClass__array *sidlarray)

#define SIDL_BaseClass__weakRef_NUM 5
#define SIDL_BaseClass__weakRef_RETURN PyObject *
#define SIDL_BaseClass__weakRef_PROTO (struct SIDL_BaseClass__object *sidlobj)

#define SIDL_BaseClass_deref_NUM 6
#define SIDL_BaseClass_deref_RETURN void
#define SIDL_BaseClass_deref_PROTO (struct SIDL_BaseClass__object *sidlobj)

#define SIDL_BaseClass__newRef_NUM 7
#define SIDL_BaseClass__newRef_RETURN PyObject *
#define SIDL_BaseClass__newRef_PROTO (struct SIDL_BaseClass__object *sidlobj)

#define SIDL_BaseClass__addRef_NUM 8
#define SIDL_BaseClass__addRef_RETURN void
#define SIDL_BaseClass__addRef_PROTO (struct SIDL_BaseClass__object *sidlobj)

#define SIDL_BaseClass__API_NUM 9

#ifdef SIDL_BaseClass_INTERNAL

/*
 * This declaration is not for clients.
 */

static SIDL_BaseClass__wrap_RETURN
SIDL_BaseClass__wrap
SIDL_BaseClass__wrap_PROTO;

static SIDL_BaseClass__convert_RETURN
SIDL_BaseClass__convert
SIDL_BaseClass__convert_PROTO;

static SIDL_BaseClass__convert_python_array_RETURN
SIDL_BaseClass__convert_python_array
SIDL_BaseClass__convert_python_array_PROTO;

static SIDL_BaseClass__convert_sidl_array_RETURN
SIDL_BaseClass__convert_sidl_array
SIDL_BaseClass__convert_sidl_array_PROTO;

static SIDL_BaseClass__destroy_sidl_array_RETURN
SIDL_BaseClass__destroy_sidl_array
SIDL_BaseClass__destroy_sidl_array_PROTO;

static SIDL_BaseClass__weakRef_RETURN
SIDL_BaseClass__weakRef
SIDL_BaseClass__weakRef_PROTO;

static SIDL_BaseClass_deref_RETURN
SIDL_BaseClass_deref
SIDL_BaseClass_deref_PROTO;

static SIDL_BaseClass__newRef_RETURN
SIDL_BaseClass__newRef
SIDL_BaseClass__newRef_PROTO;

static SIDL_BaseClass__addRef_RETURN
SIDL_BaseClass__addRef
SIDL_BaseClass__addRef_PROTO;

#else

static void **SIDL_BaseClass__API;

#define SIDL_BaseClass__wrap \
  (*((SIDL_BaseClass__wrap_RETURN (*) \
  SIDL_BaseClass__wrap_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__wrap_NUM])))

#define SIDL_BaseClass__convert \
  (*((SIDL_BaseClass__convert_RETURN (*) \
  SIDL_BaseClass__convert_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__convert_NUM])))

#define SIDL_BaseClass__convert_python_array \
  (*((SIDL_BaseClass__convert_python_array_RETURN (*) \
  SIDL_BaseClass__convert_python_array_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__convert_python_array_NUM])))

#define SIDL_BaseClass__convert_sidl_array \
  (*((SIDL_BaseClass__convert_sidl_array_RETURN (*) \
  SIDL_BaseClass__convert_sidl_array_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__convert_sidl_array_NUM])))

#define SIDL_BaseClass__destroy_sidl_array \
  (*((SIDL_BaseClass__destroy_sidl_array_RETURN (*) \
  SIDL_BaseClass__destroy_sidl_array_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__destroy_sidl_array_NUM])))

#define SIDL_BaseClass__weakRef \
  (*((SIDL_BaseClass__weakRef_RETURN (*) \
  SIDL_BaseClass__weakRef_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__weakRef_NUM])))

#define SIDL_BaseClass_deref \
  (*((SIDL_BaseClass_deref_RETURN (*) \
  SIDL_BaseClass_deref_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass_deref_NUM])))

#define SIDL_BaseClass__newRef \
  (*((SIDL_BaseClass__newRef_RETURN (*) \
  SIDL_BaseClass__newRef_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__newRef_NUM])))

#define SIDL_BaseClass__addRef \
  (*((SIDL_BaseClass__addRef_RETURN (*) \
  SIDL_BaseClass__addRef_PROTO) \
  (SIDL_BaseClass__API \
  [SIDL_BaseClass__addRef_NUM])))

#define SIDL_BaseClass__import() \
{ \
  PyObject *module = PyImport_ImportModule("SIDL.BaseClass"); \
  if (module != NULL) { \
    PyObject *module_dict = PyModule_GetDict(module); \
    PyObject *c_api_object = \
      PyDict_GetItemString(module_dict, "_C_API"); \
    if (PyCObject_Check(c_api_object)) { \
      SIDL_BaseClass__API = \
        (void **)PyCObject_AsVoidPtr(c_api_object); \
    } \
    Py_DECREF(module); \
  } \
}

#endif

#ifdef __cplusplus
}
#endif

#endif
