c CLASS = A
c  
c  
c  This file is generated automatically by the setparams utility.
c  It sets the number of processors and the class of the NPB
c  in this directory. Do not modify it by hand.
c  

c full problem size
        integer isiz1, isiz2, isiz3
        parameter (isiz1=64, isiz2=64, isiz3=64)

c number of iterations and how often to print the norm
        integer itmax_default, inorm_default
        parameter (itmax_default=250, inorm_default=250)
        double precision dt_default
        parameter (dt_default = 2.0d0)
        logical  convertdouble
        parameter (convertdouble = .false.)
        character compiletime*11
        parameter (compiletime='05 Dec 2017')
        character npbversion*5
        parameter (npbversion='3.3.1')
        character cs1*8
        parameter (cs1='gfortran')
        character cs2*6
        parameter (cs2='$(F77)')
        character cs3*6
        parameter (cs3='-lgcov')
        character cs4*6
        parameter (cs4='(none)')
        character cs5*31
        parameter (cs5='-O3 -g -fopenmp -mcmodel=medium')
        character cs6*31
        parameter (cs6='-O3 -g -fopenmp -mcmodel=medium')
        character cs7*6
        parameter (cs7='randi8')
