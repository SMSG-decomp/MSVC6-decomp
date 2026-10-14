void __cdecl class_declare_deleting_destructors(c1_symbol *cls,c1_symbol *dtor)

{
  c1_class_record *pcVar1;
  c1_vbase_vector *pcVar2;
  c1_symbol *fn;
  c1_symbol *fn_00;
  void *pvVar3;
  int iVar4;
  c1_vbase_vector *local_18;
  short local_14;
  
  fn = class_declare_implicit_member(cls,6,'\x01','\0');
  fn_00 = class_declare_implicit_member(cls,7,'\x01','\0');
  fn->flags2 = (fn->flags2 ^ dtor->flags2) & 3 ^ fn->flags2;
  fn_00->flags2 = (fn_00->flags2 ^ dtor->flags2) & 3 ^ fn_00->flags2;
  if ((dtor->flags21 & 2) != 0) {
    fn->flags21 = fn->flags21 | 2;
    fn->name->flags = fn->name->flags | 0x100000;
    (fn->x28).bytes.unk2a = (dtor->x28).bytes.unk2a;
    fn->detail = dtor->detail;
    if ((*(byte *)((int)&dtor->tail + 10) & 0x10) == 0) {
      pvVar3 = (void *)0x0;
    }
    else {
      pvVar3 = sym_this_adjustment(dtor);
    }
    sym_set_this_adjustment(fn,pvVar3);
    fn_00->flags21 = fn_00->flags21 | 2;
    fn_00->name->flags = fn_00->name->flags | 0x100000;
    (fn_00->x28).bytes.unk2a = (dtor->x28).bytes.unk2a;
    fn_00->detail = dtor->detail;
    if ((*(byte *)((int)&dtor->tail + 10) & 0x10) == 0) {
      pvVar3 = (void *)0x0;
    }
    else {
      pvVar3 = sym_this_adjustment(dtor);
    }
    sym_set_this_adjustment(fn_00,pvVar3);
    *(byte *)((int)&fn_00->tail + 9) = *(byte *)((int)&fn_00->tail + 9) | 2;
    class_map_vector_to_scalar_deleting_dtor(fn_00,fn);
  }
  pcVar1 = (cls->detail).cls;
  pcVar2 = pcVar1->vbases;
  if (pcVar2 != (c1_vbase_vector *)0x0) {
    local_14 = 0;
    local_18 = pcVar2;
  }
  do {
    if (pcVar2 == (c1_vbase_vector *)0x0) {
      return;
    }
    if (local_18 == (c1_vbase_vector *)0x0) {
      return;
    }
    iVar4 = (int)local_14;
    if ((int)(uint)local_18->count <= iVar4) {
      return;
    }
    local_14 = local_14 + 1;
  } while ((((local_18->data[iVar4]->base->detail).cls)->implicit_state41 & 0x10) != 0);
  pcVar1->layout_flags3b = pcVar1->layout_flags3b | 0x20;
  class_declare_implicit_member(cls,5,'\x01','\0');
  return;
}

