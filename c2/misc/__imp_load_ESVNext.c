void __imp_load_ESVNext(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&ESVNext_exref);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

