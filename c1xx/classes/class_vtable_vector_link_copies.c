void __cdecl
class_vtable_vector_link_copies
          (c1_vtable_vector *copies,c1_vtable_vector *originals,c1_symbol *base_entry)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  
  sVar4 = 0;
  sVar3 = 0;
  while( true ) {
    if ((copies == (c1_vtable_vector *)0x0) ||
       (iVar1 = (int)sVar4, (int)(uint)copies->count <= iVar1)) {
      return;
    }
    sVar4 = sVar4 + 1;
    if (originals == (c1_vtable_vector *)0x0) {
      return;
    }
    iVar2 = (int)sVar3;
    if ((int)(uint)originals->count <= iVar2) break;
    sVar3 = sVar3 + 1;
    class_vtable_record_set_path(copies->data[iVar1],base_entry,originals->data[iVar2]);
  }
  return;
}

