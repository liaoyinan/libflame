#include "FLA_lapack2flame_return_defs.h"
#include "FLA_f2c.h" /* Table of constant values */
static int c__1 = 1;
static int c_n1 = -1;

int zgeqp3_check(int *m, int *n, dcomplex *a, int *lda, int *jpvt, dcomplex *tau, dcomplex *work, int *lwork, double *rwork, int *info)
{
    /* System generated locals */
    int a_dim1, a_offset, i__1;

    /* Local variables */
    int nb, iws, minmn;
    int lwkopt;
    logical lquery;

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --jpvt;
    --tau;
    --work;
    --rwork;
    /* Function Body */
    *info = 0;
    lquery = *lwork == -1;
    if (*m < 0)
    {
        *info = -1;
    }
    else if (*n < 0)
    {
        *info = -2;
    }
    else if (*lda < max(1,*m))
    {
        *info = -4;
    }
    if (*info == 0)
    {
        minmn = min(*m,*n);
        if (minmn == 0)
        {
            iws = 1;
            lwkopt = 1;
        }
        else
        {
            iws = *n + 1;
            nb = ilaenv_(&c__1, "ZGEQRF", " ", m, n, &c_n1, &c_n1);
            lwkopt = (*n + 1) * nb;
        }
        work[1].real = (double) lwkopt;
        work[1].imag = 0.; // , expr subst
        if (*lwork < iws && ! lquery)
        {
            *info = -8;
        }
    }
    if (*info != 0)
    {
        i__1 = -(*info);
        xerbla_("ZGEQP3", &i__1);
        return LAPACK_FAILURE;
    }
    else if (lquery)
    {
        return LAPACK_QUERY_RETURN;
    }
    /* Quick return if possible. */
    if (minmn == 0)
    {
        return LAPACK_QUICK_RETURN;
    }
    return LAPACK_SUCCESS;
}
