void __imp_load_ObjectCodeGet(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&ObjectCodeGet_exref);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

