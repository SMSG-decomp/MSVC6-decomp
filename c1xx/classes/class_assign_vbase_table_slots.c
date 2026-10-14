void __cdecl class_assign_vbase_table_slots(c1_symbol *cls)

{
  c1_vbase_vector *pcVar1;
  c1_vbase_record *vbase_rec;
  char cVar2;
  int iVar3;
  short sVar4;
  
  sVar4 = 0;
  pcVar1 = ((cls->detail).cls)->vbases;
  while ((pcVar1 != (c1_vbase_vector *)0x0 && (iVar3 = (int)sVar4, iVar3 < (int)(uint)pcVar1->count)
         )) {
    sVar4 = sVar4 + 1;
    vbase_rec = pcVar1->data[iVar3];
    cVar2 = class_vbase_find_vbtable_slot(vbase_rec,cls);
    if (cVar2 == '\0') {
      class_vbase_add_vbtable_slot(vbase_rec,cls);
    }
  }
  return;
}

