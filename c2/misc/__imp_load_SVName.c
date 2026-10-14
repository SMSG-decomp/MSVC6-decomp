void __imp_load_SVName(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&SVName_exref);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

