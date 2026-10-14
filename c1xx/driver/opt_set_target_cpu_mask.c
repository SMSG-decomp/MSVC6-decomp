void __cdecl opt_set_target_cpu_mask(void)

{
  g_target_cpu_mask = 1 << ((byte)g_opt_G_cpu & 0x1f);
  if (g_opt_GM != '\0') {
    g_target_cpu_mask = g_target_cpu_mask | 0x80;
  }
  return;
}

