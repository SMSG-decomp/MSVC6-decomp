ulonglong __cdecl conv_cast_constant(byte op,c1_node *k,c1_type *target)

{
  ushort uVar1;
  void *pvVar2;
  void *pvVar3;
  c1_type *t;
  c1_node *pcVar4;
  int iVar5;
  uint size;
  void *value_lo;
  int target_unsigned;
  void *hi;
  longlong lVar6;
  ulonglong uVar7;
  void *pvVar8;
  
  pcVar4 = k;
  uVar1 = target->code;
  pvVar2 = k->right;
  pvVar3 = k->left;
  if (((char)uVar1 < '\0') && (((uVar1 & 0x8f) == 0x86 || ((uVar1 & 0x8f) == 0x82)))) {
    uVar7._0_4_ = k->left;
    uVar7._4_4_ = k->right;
    return uVar7;
  }
  pvVar8 = pvVar2;
  if ((uVar1 & 0x110) != 0) {
    k = (c1_node *)type_size_scalar(target);
  }
  t = pcVar4->type;
  value_lo = pvVar3;
  hi = pvVar2;
  if (((t->code & 0x110) == 0) || (iVar5 = type_size_scalar(t), (int)k <= iVar5))
  goto switchD_104125af_caseD_10;
  switch(iVar5) {
  case 2:
    uVar1 = t->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      value_lo = (void *)(((int)pvVar3 << 0x10) >> 0x10);
      hi = (void *)(((int)pvVar3 << 0x10) >> 0x1f);
    }
    else {
      value_lo = (void *)((uint)pvVar3 & 0xffff);
      hi = (void *)0x0;
    }
    pvVar8 = hi;
    if (value_lo == pvVar3) {
      if (hi != pvVar2) {
        uVar7 = conv_warn_cast_truncates(t,(uint)value_lo,(int)hi,(int)hi,op,(int)k,target);
        return uVar7;
      }
      goto switchD_104125af_caseD_10;
    }
    if (op == 100) {
      diag_warning(4,0x136);
      goto switchD_104125af_caseD_10;
    }
    break;
  default:
    uVar1 = t->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      value_lo = (void *)(int)(char)pvVar3;
      hi = (void *)((int)value_lo >> 0x1f);
    }
    else {
      value_lo = (void *)((uint)pvVar3 & 0xff);
      hi = (void *)0x0;
    }
    pvVar8 = hi;
    if (value_lo == pvVar3) {
      if (hi != pvVar2) {
        uVar7 = conv_warn_constant_truncation(t,(uint)value_lo,(int)hi,(int)hi,op,(int)k,target);
        return uVar7;
      }
      goto switchD_104125af_caseD_10;
    }
    if (op == 100) {
      diag_warning(4,0x136);
      goto switchD_104125af_caseD_10;
    }
    break;
  case 4:
    uVar1 = t->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      hi = (void *)((int)pvVar3 >> 0x1f);
    }
    else {
      hi = (void *)0x0;
    }
    pvVar8 = hi;
    if (hi == pvVar2) goto switchD_104125af_caseD_10;
    if (op == 100) {
      diag_warning(4,0x136);
      goto switchD_104125af_caseD_10;
    }
    break;
  case 8:
  case 0x10:
    goto switchD_104125af_caseD_10;
  }
  pvVar8 = hi;
  diag_warning(2,0x135);
switchD_104125af_caseD_10:
  uVar1 = t->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    iVar5 = type_size_scalar(t);
    lVar6 = _allshl(('\b' - (char)iVar5) * '\b',(uint)value_lo,(uint)hi);
    iVar5 = type_size_scalar(t);
    uVar7 = _allshr(('\b' - (char)iVar5) * '\b',(int)((ulonglong)lVar6 >> 0x20),(uint)lVar6);
  }
  else {
    iVar5 = type_size_scalar(t);
    lVar6 = _allshl(('\b' - (char)iVar5) * '\b',(uint)value_lo,(uint)hi);
    iVar5 = type_size_scalar(t);
    uVar7 = _aullshr(('\b' - (char)iVar5) * '\b',(uint)((ulonglong)lVar6 >> 0x20),(uint)lVar6);
  }
  uVar1 = t->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  uVar1 = target->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    target_unsigned = 0;
  }
  else {
    target_unsigned = 1;
  }
  size = type_size_scalar(target);
  iVar5 = conv_constant_out_of_range(size,target_unsigned,iVar5,(uint)uVar7,(uint)(uVar7 >> 0x20));
  if (iVar5 != 0) {
    if (op == 100) {
      diag_warning(4,0x136);
    }
    else {
      diag_warning(2,0x135);
    }
  }
  switch(k) {
  case (c1_node *)0x2:
    uVar1 = target->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      return CONCAT44(((int)value_lo << 0x10) >> 0x1f,((int)value_lo << 0x10) >> 0x10);
    }
    return (ulonglong)((uint)value_lo & 0xffff);
  case (c1_node *)0x4:
    uVar1 = target->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      return (ulonglong)(int)value_lo;
    }
    return ZEXT48(value_lo);
  case (c1_node *)0x8:
    return CONCAT44(pvVar8,value_lo);
  case (c1_node *)0x10:
    return CONCAT44(pvVar8,value_lo);
  }
  uVar1 = target->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    return (ulonglong)(int)(char)value_lo;
  }
  return (ulonglong)((uint)value_lo & 0xff);
}

