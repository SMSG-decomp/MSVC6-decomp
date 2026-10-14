void __imp_load_FSGetEnumLocals(void)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE =
       delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,&FSGetEnumLocals_exref);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

