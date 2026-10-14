void __imp_load_FSRelease(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&FSRelease_exref);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

