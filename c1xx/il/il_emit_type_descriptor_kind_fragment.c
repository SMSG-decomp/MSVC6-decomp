void __cdecl
il_emit_type_descriptor_kind_fragment(c1_type *t,uint agg_size,int op,uint cv_flags,int is_constant)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar4 = t->code;
  if ((uVar4 & 0x110) == 0) {
    if (((byte)uVar4 >> 5 & 1) == 0) {
      if ((uVar4 & 0x200) == 0) {
        if (((byte)uVar4 >> 6 & 1) == 0) {
          if ((uVar4 & 0x400) != 0) {
            uVar2 = 2;
            uVar5 = 2;
            goto LAB_1042b14d;
          }
          uVar4 = 0;
        }
        else {
          uVar4 = 7;
        }
      }
      else {
        uVar5 = 6;
        uVar4 = 6;
        if (op != 0x27) {
          agg_size = type_size_checked(t);
          uVar2 = -(uint)(agg_size < 0x20) & agg_size;
          goto LAB_1042b14d;
        }
      }
      uVar5 = uVar4;
      uVar2 = 0;
    }
    else if (is_constant == 1) {
      uVar5 = 10;
      uVar2 = 10;
    }
    else {
      uVar5 = 5;
      uVar2 = type_size_scalar(t);
    }
  }
  else {
    if (((uVar4 & 0x2000) != 0) ||
       (((((uVar4 & 0xfff) == 0x11 && ((uVar4 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))
        || (uVar5 = 1, (uVar4 & 0xfff) == 0x10)))) {
      uVar5 = 2;
    }
    uVar2 = type_size_scalar(t);
  }
LAB_1042b14d:
  uVar4 = (ushort)(uVar2 << 4) | uVar5;
  if ((cv_flags & 0x40) != 0) {
    uVar4 = uVar4 | 0x1000;
  }
  if ((cv_flags & 0x20) != 0) {
    uVar4 = uVar4 | 0x2000;
  }
  if (((char)t->code < '\0') && ((t->flags & 0x100) != 0)) {
    uVar4 = uVar4 | 0x4000;
  }
  if (0x7f < uVar4) {
    if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) &&
       (iVar3 = il_buffer_grow(&g_il_ex.bytes,2), iVar3 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = (byte)(uVar4 >> 8) | 0x80;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
  }
  if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) &&
     (iVar3 = il_buffer_grow(&g_il_ex.bytes,2), iVar3 == 0)) {
    bVar1 = 0;
  }
  else {
    bVar1 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar1;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.cur = (c1_u8)uVar4;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
  }
  if (uVar5 == 6) {
    if (uVar2 != 0) {
      return;
    }
    if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 6) &&
       (iVar3 = il_buffer_grow(&g_il_ex.bytes,6), iVar3 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
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
    return;
  }
  return;
}

