c1_keyed_cell * __cdecl class_first_vfptr_path(c1_symbol *cls)

{
  c1_vbase_vector *pcVar1;
  c1_vtable_vector *pcVar2;
  int iVar3;
  c1_keyed_cell *pcVar4;
  short sVar5;
  
  sVar5 = 0;
  pcVar2 = ((cls->detail).cls)->vftables;
  pcVar1 = ((cls->detail).cls)->vbases;
  while( true ) {
    if ((pcVar2 != (c1_vtable_vector *)0x0) && (pcVar2->count != 0)) {
      pcVar4 = scope_list_from_class(*pcVar2->data,cls);
      return pcVar4;
    }
    if ((pcVar1 == (c1_vbase_vector *)0x0) ||
       (iVar3 = (int)sVar5, (int)(uint)pcVar1->count <= iVar3)) break;
    sVar5 = sVar5 + 1;
    pcVar2 = pcVar1->data[iVar3]->vftables;
  }
  return (c1_keyed_cell *)0x0;
}

