void __cdecl drv_bd_disable_pass(optrec *r)

{
  uchar *hit;
  cl_u32 *flags;
  char which;
  
  flags = &g_passes[0].flags;
  which = *r->value;
  do {
    if (which == '.') {
LAB_0040291f:
      *flags = *flags & 0xfffffffe;
    }
    else {
      hit = _mbschr((uchar *)r->value,(uint)(byte)flags[-1]);
      if (hit != (uchar *)0x0) goto LAB_0040291f;
    }
    flags = flags + 9;
    if (0x40b1d3 < (int)flags) {
      return;
    }
  } while( true );
}

