void __cdecl drv_bc_copy_pass_enable(optrec *r)

{
  cl_u32 *flags;
  int i;
  char *letter;
  bool found;
  char **value;
  
  value = &r->value;
  found = false;
  flags = &g_passes[0].flags;
  do {
    if (0x40b1d3 < (int)flags) break;
    if ((char)flags[-1] == **value) {
      r = (optrec *)(*flags & 1);
      found = true;
    }
    flags = flags + 9;
  } while (!found);
  if (r != (optrec *)0x0) {
    i = 0;
    letter = &g_passes[0].letter;
    do {
      if (*letter == (*value)[1]) {
        g_passes[i].flags = (g_passes[i].flags ^ (uint)r) & 1 ^ g_passes[i].flags;
        return;
      }
      letter = letter + 0x24;
      i = i + 1;
    } while ((int)letter < 0x40b1d0);
  }
  return;
}

