void __imp_load_ESVRelease(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&ESVRelease_exref);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

