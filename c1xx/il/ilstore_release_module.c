void __cdecl ilstore_release_module(void)

{
  (*g_ilmod->vtbl->release)();
  g_ilmod = (c1xx_ilmod *)0x0;
  g_ilstore_module_ni = 0;
  return;
}

