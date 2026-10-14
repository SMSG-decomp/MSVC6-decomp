void ilstore_release_module(void)

{
  (*g_ilmod->vtbl->Release)(g_ilmod);
  g_ilmod = (ILMod *)0x0;
  g_ilstore_module_ni = 0;
  return;
}

