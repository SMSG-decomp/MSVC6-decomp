int DllMain(void *instance,ulong reason,void *reserved)

{
  g_module_handle = instance;
  if (reason == 1) {
    DisableThreadLibraryCalls(instance);
    return 1;
  }
  if ((reason == 0) && (g_data_section_copy != (uint *)0x0)) {
    mem_free(g_data_section_copy);
  }
  return 1;
}

