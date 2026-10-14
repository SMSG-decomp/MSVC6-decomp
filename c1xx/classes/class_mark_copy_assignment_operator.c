void __cdecl class_mark_copy_assignment_operator(c1_symbol *fn)

{
  int iVar1;
  int *piVar2;
  byte bVar3;
  c1_symbol *pcVar4;
  byte bVar5;
  c1_type *param_type;
  
  if (fn->name == g_name_operator_assign) {
    iVar1 = *(int *)(((uint)fn->type & -(uint)((fn->type->code & 0x80) != 0)) + 8);
    piVar2 = *(int **)(iVar1 + 0xc);
    if ((*piVar2 == 1) && (*(char *)(iVar1 + 4) == '\0')) {
      param_type = (c1_type *)piVar2[2];
      if ((param_type->code & 0x200) == 0) {
        bVar3 = (byte)param_type->code;
        if (-1 < (char)bVar3) {
          return;
        }
        if ((bVar3 & 0x8f) != 0x80) {
          return;
        }
        if ((param_type->base->code & 0x200) == 0) {
          return;
        }
        pcVar4 = (param_type->base->extra).cls;
      }
      else {
        pcVar4 = (param_type->extra).cls;
      }
      if (pcVar4 == g_class_def_stack[g_class_depth].cls) {
        *(byte *)((int)&fn->tail + 8) = *(byte *)((int)&fn->tail + 8) | 0x80;
        bVar3 = (byte)param_type->code;
        if (((char)bVar3 < '\0') && ((bVar3 & 0x8f) == 0x80)) {
          bVar5 = (byte)param_type->base->flags;
        }
        else {
          bVar5 = (byte)param_type->flags;
        }
        if (((char)bVar3 < '\0') && ((bVar3 & 0x8f) == 0x80)) {
          bVar3 = (byte)param_type->base->flags;
        }
        else {
          bVar3 = (byte)param_type->flags;
        }
        *(byte *)((int)&fn->tail + 10) =
             (bVar3 >> 5 & 2 | bVar5 >> 5 & 1) << 5 | *(byte *)((int)&fn->tail + 10) & 0x9f;
      }
    }
  }
  return;
}

