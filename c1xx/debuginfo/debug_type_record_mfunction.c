int __cdecl debug_type_record_mfunction(c1_type *type,uint this_adjust)

{
  c1_u16 cVar1;
  uint *puVar2;
  ushort uVar3;
  c1_type *pcVar4;
  c1_u32 cVar5;
  c1_type *pcVar6;
  int iVar7;
  int iVar8;
  uint this_type_index;
  c1_symbol *sym;
  ushort *body;
  
  body = g_cv_record_body;
  puVar2 = g_debug_index_queue;
  cVar1 = type->code;
  pcVar4 = type_get_base(type);
  cVar5 = debug_type_index(pcVar4);
  pcVar4 = (c1_type *)**(undefined4 **)((-(uint)((cVar1 & 0x80) != 0) & (uint)type) + 8);
  uVar3 = type->code & 0x8f;
  if (uVar3 == 0x85) {
    pcVar6 = type_base(((type->extra).params)->this_type);
    sym = (pcVar6->extra).cls;
  }
  else if ((uVar3 == 0x8a) || (uVar3 == 0x8e)) {
    sym = (type->extra).cls;
  }
  else {
    sym = (c1_symbol *)0x0;
  }
  iVar7 = debug_type_record_class_forward(sym);
  iVar8 = debug_type_record_arglist((type->extra).count);
  if (((type->code & 0x8f) == 0x85) && ((((type->extra).cls)->flags5 & 1) == 0)) {
    this_type_index = debug_type_index(pcVar4);
  }
  else {
    this_type_index = 0;
  }
  *body = 0x1009;
  *(c1_u32 *)(body + 1) = cVar5;
  *(int *)(body + 3) = iVar7;
  *(uint *)(body + 5) = this_type_index;
  iVar7 = debug_cv_calling_convention(type->flags);
  *(char *)(body + 7) = (char)iVar7;
  *(undefined1 *)((int)body + 0xf) = 0;
  iVar7 = type_function_param_count((type->extra).params);
  body[8] = (ushort)iVar7;
  *(int *)(body + 9) = iVar8;
  *(uint *)(body + 0xb) = this_adjust;
  iVar7 = cvserver_emit_type(0x1a);
  g_debug_index_queue = puVar2;
  return iVar7;
}

