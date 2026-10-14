void __imp_load_FSGetFrameInfo(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&FSGetFrameInfo_exref)
  ;
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

