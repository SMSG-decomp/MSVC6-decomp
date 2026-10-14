void __cdecl class_build_vbase_destructor_calls(c1_symbol *cls,c1_node *object)

{
  short sVar1;
  short sVar2;
  short sVar3;
  c1_vbase_vector *pcVar4;
  short sVar5;
  int iVar6;
  c1_type *type;
  c1_node *pcVar7;
  c1_node *left;
  c1_symbol *pcVar8;
  c1_vbase_vector *local_18;
  short local_14;
  
  pcVar4 = ((cls->detail).cls)->vbases;
  if (pcVar4 != (c1_vbase_vector *)0x0) {
    local_14 = 0;
    local_18 = pcVar4;
  }
  cls = (c1_symbol *)symtab_record_new_kind4();
  while (((pcVar4 != (c1_vbase_vector *)0x0 && (local_18 != (c1_vbase_vector *)0x0)) &&
         (iVar6 = (int)local_14, iVar6 < (int)(uint)local_18->count))) {
    local_14 = local_14 + 1;
    pcVar8 = local_18->data[iVar6]->base;
    iVar6 = local_18->data[iVar6]->offset;
    if ((((pcVar8->detail).cls)->implicit_state41 & 0x10) == 0) {
      type = type_this_pointer(pcVar8,*(byte *)(((uint)object->type &
                                                -(uint)((object->type->code & 0x80) != 0)) + 2) &
                                      0x18,0);
      pcVar7 = tree_new_int_constant(iVar6);
      left = tree_copy_to_arena(object,0);
      pcVar7 = tree_new_node('Q',left,pcVar7,type);
      pcVar7 = expr_build_destructor_call(pcVar8,pcVar7,1,1,0);
      if (pcVar7 != (c1_node *)0x0) {
        sVar1._0_1_ = cls->kind;
        sVar1._1_1_ = cls->flags1;
        sVar2._0_1_ = cls->flags2;
        sVar2._1_1_ = cls->flags3;
        if (sVar1 == sVar2) {
          cls = vector_grow_checked((c1_symbol_vector *)cls);
        }
        sVar3._0_1_ = cls->kind;
        sVar3._1_1_ = cls->flags1;
        *(c1_node **)(&cls->flags4 + sVar3 * 4) = pcVar7;
        *(short *)cls = *(short *)cls + 1;
      }
    }
  }
  if (cls == (c1_symbol *)0x0) {
    sVar5 = 0;
  }
  else {
    sVar5._0_1_ = cls->kind;
    sVar5._1_1_ = cls->flags1;
  }
  sVar5 = sVar5 + -1;
  if (-1 < sVar5) {
    pcVar8 = (c1_symbol *)(&cls->flags4 + sVar5 * 4);
    iVar6 = sVar5 + 1;
    do {
      stmt_emit_expression(*(c1_node **)pcVar8);
      pcVar8 = (c1_symbol *)((int)(pcVar8 + 0xffffffff) + 0x34);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  vector_release((int)cls);
  return;
}

