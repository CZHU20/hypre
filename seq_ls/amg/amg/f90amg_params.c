/*BHEADER**********************************************************************
 * (c) 1996   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/

/******************************************************************************
 *
 * AMG parameter functions (Fortran 90 interface)
 *
 *****************************************************************************/

#include "headers.h"


/*--------------------------------------------------------------------------
 * Routines to set the setup phase parameters
 *--------------------------------------------------------------------------*/

void      amg_setlevmax__(levmax, data)
int      *levmax;
int      *data;
{
   amg_SetLevMax(*levmax, (void *) *data);
}

void      amg_setncg__(ncg, data)
int      *ncg;
int      *data;
{
   amg_SetNCG(*ncg, (void *) *data);
}

void      amg_setecg__(ecg, data)
double   *ecg;
int      *data;
{
   amg_SetECG(*ecg, (void *) *data);
}

void      amg_setnwt__(nwt, data)
int      *nwt;
int      *data;
{
   amg_SetNWT(*nwt, (void *) *data);
}

void      amg_setewt__(ewt, data)
double   *ewt;
int      *data;
{
   amg_SetEWT(*ewt, (void *) *data);
}

void      amg_setnstr__(nstr, data)
int      *nstr;
int      *data;
{
   amg_SetNSTR(*nstr, (void *) *data);
}

		  		      
/*--------------------------------------------------------------------------
 * Routines to set the solve phase parameters
 *--------------------------------------------------------------------------*/

void      amg_setncyc__(ncyc, data)
int      *ncyc;
int      *data;
{
   amg_SetNCyc(*ncyc, (void *) *data);
}

void      amg_setmu__(mu, data)
int      *mu;
int      *data;
{
   amg_SetMU(mu, (void *) *data);
}

void      amg_setntrlx__(ntrlx, data)
int      *ntrlx;
int      *data;
{
   amg_SetNTRLX(ntrlx, (void *) *data);
}

void      amg_setiprlx__(iprlx, data)
int      *iprlx;
int      *data;
{
   amg_SetIPRLX(iprlx, (void *) *data);
}

void      amg_setierlx__(ierlx, data)
int      *ierlx;
int      *data;
{
   amg_SetIERLX(ierlx, (void *) *data);
}

void      amg_setiurlx__(iurlx, data)
int      *iurlx;
int      *data;
{
   amg_SetIURLX(iurlx, (void *) *data);
}

		  		     

/*--------------------------------------------------------------------------
 * Routine to set up logging
 *--------------------------------------------------------------------------*/

void      amg_setlogging__(ioutdat, log_file_name, data, log_file_name_len)
int      *ioutdat;
char     *log_file_name;
int      *data;
int       log_file_name_len;
{
   amg_SetLogging(*ioutdat,log_file_name, (void *) *data);    
}

/*--------------------------------------------------------------------------
 * Routines to set the problem data parameters
 *--------------------------------------------------------------------------*/

void      amg_setnumunknowns__(num_unknowns, data)
int      *num_unknowns;  
int      *data;
{
   amg_SetNumUnknowns(*num_unknowns, (void *) *data);
}

void      amg_setnumpoints__(num_points, data)
int      *num_points;    
int      *data;
{
   amg_SetNumPoints(*num_points, (void *) *data);
}

void      amg_setiu__(iu, data)
int      *iu;            
int      *data;
{
   amg_SetIU(iu, (void *) *data);
}

void      amg_setip__(ip, data)
int      *ip;            
int      *data;
{
   amg_SetIP(ip, (void *) *data);
}

void      amg_setiv__(iv, data)
int      *iv;            
int      *data;
{
   amg_SetIV(iv, (void *) *data);
}

void      amg_setxp__(xp, data)
double   *xp;            
int      *data;
{
   amg_SetXP(xp, (void *) *data);
}

void      amg_setyp__(yp, data)
double   *yp;            
int      *data;
{
   amg_SetYP(yp, (void *) *data);
}

void      amg_setzp__(zp, data)
double   *zp;            
int      *data;
{
   amg_SetZP(zp, (void *) *data);
}

