void __cdecl class_check_copy_constructor_signature(c1_symbol *sym)

{
  byte *pbVar1;
  c1_type *pcVar2;
  int iVar3;
  c1_symbol *pcVar4;
  byte bVar5;
  c1_type *param_type;
  
  pcVar2 = sym->type;
  if ((pcVar2->flags & 0x4000) != 0) {
    *(byte *)((int)&sym->tail + 8) = *(byte *)((int)&sym->tail + 8) | 0x10;
    return;
  }
  iVar3 = *(int *)(((uint)pcVar2 & -(uint)((pcVar2->code & 0x80) != 0)) + 8);
  if (((pcVar2->flags & 0x8000) != 0) && (**(int **)(iVar3 + 0xc) == 1)) {
    *(byte *)((int)&sym->tail + 8) = *(byte *)((int)&sym->tail + 8) | 0x30;
    return;
  }
  if (**(uint **)(iVar3 + 0xc) == (uint)*(byte *)(iVar3 + 4)) {
    pbVar1 = (byte *)((int)&sym->tail + 8);
    *pbVar1 = *pbVar1 | 0x10;
  }
  else if (**(uint **)(iVar3 + 0xc) - (uint)*(byte *)(iVar3 + 4) != 1) {
    return;
  }
  param_type = *(c1_type **)(*(int *)(iVar3 + 0xc) + 8);
  bVar5 = (byte)param_type->code;
  if (((((char)bVar5 < '\0') && ((bVar5 & 0x8f) == 0x80)) && ((param_type->base->code & 0x200) != 0)
      ) && ((param_type->base->extra).cls == g_class_def_stack[g_class_depth].cls)) {
    *(byte *)((int)&sym->tail + 8) = *(byte *)((int)&sym->tail + 8) | 0x20;
    bVar5 = (byte)param_type->base->flags;
    *(byte *)((int)&sym->tail + 10) =
         (bVar5 >> 5 & 2 | bVar5 >> 5 & 1) << 5 | *(byte *)((int)&sym->tail + 10) & 0x9f;
    return;
  }
  if (((param_type->code & 0x200) != 0) &&
     (pcVar4 = g_class_def_stack[g_class_depth].cls, (param_type->extra).cls == pcVar4)) {
    diag_error(0x28c,pcVar4,pcVar4);
    bVar5 = *(byte *)((int)&sym->tail + 8);
    sym->flags3 = sym->flags3 | 4;
    *(byte *)((int)&sym->tail + 8) = bVar5 | 0x20;
    return;
  }
  *(byte *)((int)&sym->tail + 8) = *(byte *)((int)&sym->tail + 8) | 0x40;
  g_compile_flags_cc = g_compile_flags_cc | 0x80;
  return;
}

