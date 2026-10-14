uint32_t __fastcall
coff_add_weak_external
          (char *name,uint16_t section,char storage_class,int value,uint16_t type,uint32_t tag_index
          ,uint8_t characteristics,uint32_t key)

{
  uint32_t key_00;
  uint32_t uVar1;
  
  key_00 = key;
  if (((g_coff_incremental_update == 0) || (key == 0)) ||
     (uVar1 = coff_hash64_find(key,section), uVar1 == 0)) {
    uVar1 = coff_add_symbol_with_aux(name,section,storage_class,value,type,(void **)&key,key_00);
    *(uint32_t *)key = tag_index;
    *(uint *)(key + 4) = (uint)characteristics;
  }
  return uVar1;
}

