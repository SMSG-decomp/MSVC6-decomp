void __cdecl il_emit_type_descriptor(int op,c1_node *n,int is_constant)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  uint agg_size;
  
  agg_size = 0;
  pcVar5 = n->type;
  pcVar4 = pcVar5;
  if ((pcVar5->code & 0x8f) == 0x83) {
    pcVar4 = type_skip_arrays(pcVar5->base);
  }
  uVar1 = pcVar4->flags;
  if (-1 < (char)pcVar5->code) {
    uVar3 = pcVar5->code;
    if ((uVar3 & 0x110) == 0) {
      if (((byte)uVar3 >> 5 & 1) == 0) {
        if ((uVar3 >> 9 & 1) == 0) {
          if (((byte)uVar3 >> 6 & 1) == 0) {
            if ((uVar3 >> 10 & 1) != 0) {
              uVar8 = 2;
              uVar7 = 2;
              goto LAB_1042b14d;
            }
            uVar3 = 0;
          }
          else {
            uVar3 = 7;
          }
        }
        else {
          uVar7 = 6;
          uVar3 = 6;
          if (op != 0x27) {
            agg_size = type_size_checked(pcVar5);
            uVar8 = -(uint)(agg_size < 0x20) & agg_size;
            goto LAB_1042b14d;
          }
        }
        uVar7 = uVar3;
        uVar8 = 0;
      }
      else if (is_constant == 1) {
        uVar7 = 10;
        uVar8 = 10;
      }
      else {
        uVar7 = 5;
        uVar8 = type_size_scalar(pcVar5);
      }
    }
    else {
      if (((uVar3 & 0x2000) != 0) ||
         (((((uVar3 & 0xfff) == 0x11 && ((uVar3 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))
          || (uVar7 = 1, (uVar3 & 0xfff) == 0x10)))) {
        uVar7 = 2;
      }
      uVar8 = type_size_scalar(pcVar5);
    }
    goto LAB_1042b14d;
  }
  uVar3 = pcVar5->code & 0x8f;
  if ((uVar3 == 0x8a) || (uVar3 == 0x8e)) {
    if ((uVar3 == 0x8e) && (iVar6 = class_complete_type_of(pcVar5), iVar6 == 1)) {
      uVar8 = 4;
      uVar7 = 3;
      goto LAB_1042b14d;
    }
    bVar2 = type_member_pointer_is_aggregate(pcVar5);
    if (bVar2 == 0) {
      if ((pcVar5->code & 0x8f) == 0x8a) {
        pcVar5 = type_int();
        n->type = pcVar5;
        il_emit_type_descriptor_kind_fragment(pcVar5,agg_size,op,uVar1 & 0x3e0,is_constant);
        return;
      }
    }
    else {
      if (op != 0x27) {
        agg_size = type_size_checked(pcVar5);
        uVar8 = -(uint)(agg_size < 0x20) & agg_size;
        uVar7 = 6;
        goto LAB_1042b14d;
      }
      if (*(char *)n->left != -100) {
        uVar8 = 0;
        uVar7 = 6;
        goto LAB_1042b14d;
      }
    }
  }
  uVar8 = 4;
  uVar7 = 3;
LAB_1042b14d:
  uVar3 = (ushort)(uVar8 << 4) | uVar7;
  if ((uVar1 & 0x40) != 0) {
    uVar3 = uVar3 | 0x1000;
  }
  if ((uVar1 & 0x20) != 0) {
    uVar3 = uVar3 | 0x2000;
  }
  if (((char)pcVar5->code < '\0') && ((pcVar5->flags & 0x100) != 0)) {
    uVar3 = uVar3 | 0x4000;
  }
  if (0x7f < uVar3) {
    if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) &&
       (iVar6 = il_buffer_grow(&g_il_ex.bytes,2), iVar6 == 0)) {
      bVar2 = 0;
    }
    else {
      bVar2 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar2;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = (byte)(uVar3 >> 8) | 0x80;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
  }
  if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) &&
     (iVar6 = il_buffer_grow(&g_il_ex.bytes,2), iVar6 == 0)) {
    bVar2 = 0;
  }
  else {
    bVar2 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar2;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.cur = (c1_u8)uVar3;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
  }
  if ((uVar7 == 6) && (uVar8 == 0)) {
    if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 6) &&
       (iVar6 = il_buffer_grow(&g_il_ex.bytes,6), iVar6 == 0)) {
      bVar2 = 0;
    }
    else {
      bVar2 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar2;
    if (g_il_ex.open != 0) {
      if ((agg_size & 0xffffff80) == 0) {
        *g_il_ex.bytes.cur = (c1_u8)agg_size;
        g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        return;
      }
      *g_il_ex.bytes.cur = 0x80;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
      *(uint *)g_il_ex.bytes.cur = agg_size;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
    }
  }
  return;
}

