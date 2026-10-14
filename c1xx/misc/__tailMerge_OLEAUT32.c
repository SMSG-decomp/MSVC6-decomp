void __tailMerge_OLEAUT32(void)

{
  code *UNRECOVERED_JUMPTABLE;
  void **unaff_retaddr;
  
  UNRECOVERED_JUMPTABLE = __delayLoadHelper(&__DELAY_IMPORT_DESCRIPTOR_OLEAUT32,unaff_retaddr);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

