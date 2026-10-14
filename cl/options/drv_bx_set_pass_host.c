void __cdecl drv_bx_set_pass_host(optrec *r)

{
  char *host;
  char **host_p;
  char which;
  
  host_p = &g_passes[0].host;
  which = *r->value;
  do {
    if ((which == '.') || (*(char *)(host_p + -5) == which)) {
      host = xstrdup(r->value + 1);
      *host_p = host;
    }
    host_p = host_p + 9;
  } while ((int)host_p < 0x40b1e4);
  return;
}

