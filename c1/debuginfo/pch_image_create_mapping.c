void * __thiscall pch_image_create_mapping(c1_pch_image *index,uint protect,uint *handle)

{
  void *pvVar1;
  
  pvVar1 = CreateFileMappingA(index->file,(LPSECURITY_ATTRIBUTES)0x0,protect,0,0,(LPCSTR)0x0);
  if (pvVar1 == (HANDLE)0x0) {
    if (handle != (uint *)0x0) {
      CloseHandle((HANDLE)*handle);
      *handle = 0;
    }
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}

