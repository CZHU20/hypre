/*
 * File:          SIDL_BaseInterface_Module.h
 * Symbol:        SIDL.BaseInterface-v0.8.2
 * Symbol Type:   interface
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
 * to an instance of SIDL.BaseInterface.
 * This header files defines two methods that such clients
 * will need.
 *     SIDL_BaseInterface__import
 *         This should be called in the client's init
 *         module method.
 *     SIDL_BaseInterface__wrap
 *         This will wrap an IOR in a Python object.
 */

#ifndef included_SIDL_BaseInterface_MODULE
#define included_SIDL_BaseInterface_MODULE

#include "babel_config.h"
#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Forward declaration of IOR structure */
struct SIDL_BaseInterface__object;
struct SIDL_BaseInterface__array;

#define SIDL_BaseInterface__wrap_NUM 0
#define SIDL_BaseInterface__wrap_RETURN PyObject *
#define SIDL_BaseInterface__wrap_PROTO (struct SIDL_BaseInterface__object *sidlobj)

#define SIDL_BaseInterface__convert_NUM 1
#define SIDL_BaseInterface__convert_RETURN int
#define SIDL_BaseInterface__convert_PROTO (PyObject *obj, struct SIDL_BaseInterface__object **sidlobj)

#define SIDL_BaseInterface__convert_python_array_NUM 2
#define SIDL_BaseInterface__convert_python_array_RETURN int
#define SIDL_BaseInterface__convert_python_array_PROTO (PyObject *obj, struct SIDL_BaseInterface__array **sidlarray)

#define SIDL_BaseInterface__convert_sidl_array_NUM 3
#define SIDL_BaseInterface__convert_sidl_array_RETURN PyObject *
#define SIDL_BaseInterface__convert_sidl_array_PROTO (struct SIDL_BaseInterface__array *sidlarray)

#define SIDL_BaseInterface__destroy_sidl_array_NUM 4
#define SIDL_BaseInterface__destroy_sidl_array_RETURN void
#define SIDL_BaseInterface__destroy_sidl_array_PROTO (struct SIDL_BaseInterface__array *sidlarray)

#define SIDL_BaseInterface__weakRef_NUM 5
#define SIDL_BaseInterface__weakRef_RETURN PyObject *
#define SIDL_BaseInterface__weakRef_PROTO (struct SIDL_BaseInterface__object *sidlobj)

#define SIDL_BaseInterface_deref_NUM 6
#define SIDL_BaseInterface_deref_RETURN void
#define SIDL_BaseInterface_deref_PROTO (struct SIDL_BaseInterface__object *sidlobj)

#define SIDL_BaseInterface__newRef_NUM 7
#define SIDL_BaseInterface__newRef_RETURN PyObject *
#define SIDL_BaseInterface__newRef_PROTO (struct SIDL_BaseInterface__object *sidlobj)

#define SIDL_BaseInterface__addRef_NUM 8
#define SIDL_BaseInterface__addRef_RETURN void
#define SIDL_BaseInterface__addRef_PROTO (struct SIDL_BaseInterface__object *sidlobj)

#define SIDL_BaseInterface__API_NUM 9

#ifdef SIDL_BaseInterface_INTERNAL

/*
 * This declaration is not for clients.
 */

static SIDL_BaseInterface__wrap_RETURN
SIDL_BaseInterface__wrap
SIDL_BaseInterface__wrap_PROTO;

static SIDL_BaseInterface__convert_RETURN
SIDL_BaseInterface__convert
SIDL_BaseInterface__convert_PROTO;

static SIDL_BaseInterface__convert_python_array_RETURN
SIDL_BaseInterface__convert_python_array
SIDL_BaseInterface__convert_python_array_PROTO;

static SIDL_BaseInterface__convert_sidl_array_RETURN
SIDL_BaseInterface__convert_sidl_array
SIDL_BaseInterface__convert_sidl_array_PROTO;

static SIDL_BaseInterface__destroy_sidl_array_RETURN
SIDL_BaseInterface__destroy_sidl_array
SIDL_BaseInterface__destroy_sidl_array_PROTO;

static SIDL_BaseInterface__weakRef_RETURN
SIDL_BaseInterface__weakRef
SIDL_BaseInterface__weakRef_PROTO;

static SIDL_BaseInterface_deref_RETURN
SIDL_BaseInterface_deref
SIDL_BaseInterface_deref_PROTO;

static SIDL_BaseInterface__newRef_RETURN
SIDL_BaseInterface__newRef
SIDL_BaseInterface__newRef_PROTO;

static SIDL_BaseInterface__addRef_RETURN
SIDL_BaseInterface__addRef
SIDL_BaseInterface__addRef_PROTO;

#else

static void **SIDL_BaseInterface__API;

#define SIDL_BaseInterface__wrap \
  (*((SIDL_BaseInterface__wrap_RETURN (*) \
  SIDL_BaseInterface__wrap_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__wrap_NUM])))

#define SIDL_BaseInterface__convert \
  (*((SIDL_BaseInterface__convert_RETURN (*) \
  SIDL_BaseInterface__convert_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__convert_NUM])))

#define SIDL_BaseInterface__convert_python_array \
  (*((SIDL_BaseInterface__convert_python_array_RETURN (*) \
  SIDL_BaseInterface__convert_python_array_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__convert_python_array_NUM])))

#define SIDL_BaseInterface__convert_sidl_array \
  (*((SIDL_BaseInterface__convert_sidl_array_RETURN (*) \
  SIDL_BaseInterface__convert_sidl_array_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__convert_sidl_array_NUM])))

#define SIDL_BaseInterface__destroy_sidl_array \
  (*((SIDL_BaseInterface__destroy_sidl_array_RETURN (*) \
  SIDL_BaseInterface__destroy_sidl_array_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__destroy_sidl_array_NUM])))

#define SIDL_BaseInterface__weakRef \
  (*((SIDL_BaseInterface__weakRef_RETURN (*) \
  SIDL_BaseInterface__weakRef_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__weakRef_NUM])))

#define SIDL_BaseInterface_deref \
  (*((SIDL_BaseInterface_deref_RETURN (*) \
  SIDL_BaseInterface_deref_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface_deref_NUM])))

#define SIDL_BaseInterface__newRef \
  (*((SIDL_BaseInterface__newRef_RETURN (*) \
  SIDL_BaseInterface__newRef_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__newRef_NUM])))

#define SIDL_BaseInterface__addRef \
  (*((SIDL_BaseInterface__addRef_RETURN (*) \
  SIDL_BaseInterface__addRef_PROTO) \
  (SIDL_BaseInterface__API \
  [SIDL_BaseInterface__addRef_NUM])))

#define SIDL_BaseInterface__import() \
{ \
  PyObject *module = PyImport_ImportModule("SIDL.BaseInterface"); \
  if (module != NULL) { \
    PyObject *module_dict = PyModule_GetDict(module); \
    PyObject *c_api_object = \
      PyDict_GetItemString(module_dict, "_C_API"); \
    if (PyCObject_Check(c_api_object)) { \
      SIDL_BaseInterface__API = \
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
