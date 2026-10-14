void __thiscall conv_warn_possible_loss_of_data_2(void *this,c1_node *node)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  int level;
  
  cVar3 = conv_constant_warnings_enabled(this);
  if (cVar3 != '\0') {
    uVar1 = **(ushort **)((int)this + 0xc);
    uVar2 = **(ushort **)((int)this + 8);
    if ((byte)(&g_type_rank_table)[uVar1 & 0xf] < (byte)(&g_type_rank_table)[uVar2 & 0xf]) {
      level = 3;
    }
    else {
      if ((((&g_type_rank_table)[uVar1 & 0xf] != (&g_type_rank_table)[uVar2 & 0xf]) ||
          (((byte)uVar2 & 0x28) != 0x28)) || (((byte)uVar1 & 0x28) == 0x28)) goto LAB_1044dc6d;
      level = 4;
    }
    diag_warning(level,0xf4,(uint)*(byte *)this,*(ushort **)((int)this + 8),
                 *(ushort **)((int)this + 0xc));
  }
LAB_1044dc6d:
  conv_apply_standard_conversion(this,node);
  return;
}

