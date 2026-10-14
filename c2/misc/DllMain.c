uint32_t DllMain(HMODULE module,uint32_t reason,void *reserved)

{
  g_c2_module_handle = module;
  if (reason == 1) {
    DisableThreadLibraryCalls(module);
  }
  return 1;
}

