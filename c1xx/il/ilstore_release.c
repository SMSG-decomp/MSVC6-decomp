void __cdecl ilstore_release(void)

{
  (*g_ilstore->vtbl->release)();
  g_ilstore = (c1_ilstore *)0x0;
  g_ilstore_pdb = (c1xx_pdb *)0x0;
  return;
}

