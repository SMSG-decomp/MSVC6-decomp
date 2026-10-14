void __tailMerge_msobj10(FARPROC *iat_slot)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = delayload_helper(&__DELAY_IMPORT_DESCRIPTOR_msobj10,iat_slot);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

