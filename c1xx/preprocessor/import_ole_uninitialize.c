void __cdecl import_ole_uninitialize(void)

{
  if (g_import_ole_initialized == '\0') {
    return;
  }
  g_import_ole_initialized = '\0';
  CoUninitialize();
  return;
}

