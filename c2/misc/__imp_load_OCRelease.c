void __imp_load_OCRelease(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&OCRelease_exref);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

