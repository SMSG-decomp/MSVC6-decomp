void __cdecl drv_ba_enable_pass(optrec *r)

{
  cl_u32 *flags;
  char which;
  
  which = *r->value;
  flags = &g_passes[0].flags;
  do {
    if ((which == '.') || ((char)flags[-1] == which)) {
      *flags = *flags | 1;
    }
    flags = flags + 9;
  } while ((int)flags < 0x40b1d4);
  return;
}

