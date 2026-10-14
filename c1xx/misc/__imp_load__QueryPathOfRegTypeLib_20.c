long __imp_load__QueryPathOfRegTypeLib_20
               (void *guid,ushort wMaj,ushort wMin,ulong lcid,wchar_t **lpbstrPathName)

{
  code *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE =
       __delayLoadHelper(&__DELAY_IMPORT_DESCRIPTOR_OLEAUT32,&QueryPathOfRegTypeLib_exref);
  lVar1 = (*UNRECOVERED_JUMPTABLE)();
  return lVar1;
}

