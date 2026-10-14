int DllMain(void *module,int reason)

{
  g_module_handle = module;
  if (reason == 1) {
    DisableThreadLibraryCalls(module);
    return 1;
  }
  if ((reason == 0) && (g_data_section_copy != (uint *)0x0)) {
    mem_free(g_data_section_copy);
  }
  return 1;
}

