void delayload_thunk_dispatch(void)

{
  FARPROC import;
  FARPROC *slot;
  
  import = __delayLoadHelper(&__DELAY_IMPORT_DESCRIPTOR_VERSION,slot);
  (*import)();
  return;
}

