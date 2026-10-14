void __tailMerge_ole32(void)

{
  code *UNRECOVERED_JUMPTABLE;
  void **unaff_retaddr;
  
  UNRECOVERED_JUMPTABLE = __delayLoadHelper(&__DELAY_IMPORT_DESCRIPTOR_ole32,unaff_retaddr);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

