c1_vbase_record * __cdecl class_find_base_record(c1_symbol *base,c1_vbase_vector *vbases)

{
  int iVar1;
  short sVar2;
  
  if (vbases != (c1_vbase_vector *)0x0) {
    sVar2 = 0;
    while (iVar1 = (int)sVar2, iVar1 < (int)(uint)vbases->count) {
      sVar2 = sVar2 + 1;
      if (vbases->data[iVar1]->base == base) {
        return vbases->data[iVar1];
      }
    }
  }
  return (c1_vbase_record *)0x0;
}

