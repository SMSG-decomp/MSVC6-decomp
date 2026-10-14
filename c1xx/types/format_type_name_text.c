int __cdecl format_type_name_text(int buf,c1_type *type,char trailing_space)

{
  c1_type **ppcVar1;
  c1_u16 cVar2;
  ushort code;
  ushort quals;
  c1_type *pcVar3;
  c1_type *pcVar4;
  char cVar5;
  c1_u16 *pcVar6;
  int buf_00;
  char *pcVar7;
  int iVar8;
  char cVar9;
  c1_symbol *pcVar10;
  char local_10 [16];
  
  if (buf == 0) {
    buf = format_buffer_alloc();
  }
  cVar2 = type->code;
  if (cVar2 == 0x80c) {
    return buf;
  }
  if (cVar2 == 0x80e) {
    return buf;
  }
  cVar9 = (char)cVar2;
  pcVar3 = type;
  cVar5 = cVar9;
  while (cVar5 < '\0') {
    pcVar3 = pcVar3->base;
    cVar5 = (char)pcVar3->code;
  }
  code = pcVar3->code;
  pcVar3 = type;
  while (cVar9 < '\0') {
    pcVar3 = pcVar3->base;
    cVar9 = (char)pcVar3->code;
  }
  quals = pcVar3->flags;
  if ((code & 0x2000) != 0) {
    format_buffer_prepend_string(buf,"unsigned ");
  }
  if ((code & 0x1000) != 0) {
    format_buffer_prepend_string(buf,"signed ");
  }
  buf_00 = decorate_cv_text(buf,quals);
  pcVar6 = &type->code;
  cVar9 = (char)*pcVar6;
  pcVar3 = type;
  cVar5 = cVar9;
  while (cVar5 < '\0') {
    pcVar3 = pcVar3->base;
    cVar5 = (char)pcVar3->code;
  }
  pcVar4 = type;
  cVar5 = cVar9;
  if ((pcVar3->code & 0x800) != 0) {
    while (cVar9 < '\0') {
      type = type->base;
      cVar9 = (char)type->code;
    }
    cVar9 = (char)type->code;
    pcVar3 = type;
    cVar5 = cVar9;
    while (cVar5 < '\0') {
      pcVar3 = pcVar3->base;
      cVar5 = (char)pcVar3->code;
    }
    pcVar4 = type;
    if ((pcVar3->code & 0xfff) == 0x801) {
      pcVar7 = format_template_parameter_name(*(short *)&type->extra);
      if (pcVar7 == (char *)0x0) goto joined_r0x10484731;
    }
    else {
      while (cVar9 < '\0') {
        cVar9 = (char)pcVar4->base->code;
        pcVar4 = pcVar4->base;
      }
      if ((pcVar4->code & 0xfff) == 0x802) {
        format_buffer_append_string(buf_00,"generic-type-");
        sprintf(local_10,"%d",(int)*(short *)&type->extra);
        format_buffer_append_string(buf_00,local_10);
        goto joined_r0x10484731;
      }
      if (*pcVar6 != 0x80d) goto joined_r0x10484731;
      pcVar7 = "...";
    }
    format_buffer_append_string(buf_00,pcVar7);
    goto joined_r0x10484731;
  }
  while (cVar5 < '\0') {
    ppcVar1 = &pcVar4->base;
    pcVar4 = *ppcVar1;
    cVar5 = (char)(*ppcVar1)->code;
  }
  if (((pcVar4->code & 0x300) == 0) || (pcVar3 = type, (pcVar4->extra).cls == (c1_symbol *)0x0)) {
LAB_10452991:
    pcVar7 = type_keyword_text(code);
    format_buffer_append_string(buf_00,pcVar7);
    if ((*pcVar7 != '\0') &&
       ((trailing_space != '\0' ||
        (((((type->code & 0x300) != 0 ||
           (iVar8 = type_is_template_type_parameter(type), (char)iVar8 != '\0')) ||
          ((type->code & 0xfff) == 0x802)) && ((g_format_name_flags & 1) == 0)))))) {
      format_buffer_append_char(buf_00,' ');
    }
  }
  else {
    while (cVar9 < '\0') {
      cVar9 = (char)pcVar3->base->code;
      pcVar3 = pcVar3->base;
    }
    if ((pcVar3->code & 0x300) == 0) {
      pcVar10 = (c1_symbol *)0x0;
    }
    else {
      pcVar10 = (pcVar3->extra).cls;
    }
    if ((((pcVar10->detail).cls)->layout_flags3c & 8) == 0) goto LAB_10452991;
  }
  cVar9 = (char)type->code;
  pcVar3 = type;
  cVar5 = cVar9;
  while (cVar5 < '\0') {
    pcVar3 = pcVar3->base;
    cVar5 = (char)pcVar3->code;
  }
  if ((pcVar3->code & 0x300) == 0) {
    return buf_00;
  }
  pcVar4 = type;
  cVar5 = cVar9;
  if ((pcVar3->extra).cls == (c1_symbol *)0x0) {
    return buf_00;
  }
  while (cVar5 < '\0') {
    ppcVar1 = &pcVar4->base;
    pcVar4 = *ppcVar1;
    cVar5 = (char)(*ppcVar1)->code;
  }
  if ((pcVar4->code & 0x300) == 0) {
    pcVar10 = (c1_symbol *)0x0;
  }
  else {
    pcVar10 = (pcVar4->extra).cls;
  }
  if ((pcVar10->flags3 & 1) != 0) {
    while (cVar9 < '\0') {
      type = type->base;
      cVar9 = (char)type->code;
    }
    if ((type->code & 0x300) == 0) {
      pcVar10 = (c1_symbol *)0x0;
    }
    else {
      pcVar10 = (type->extra).cls;
    }
    pcVar3 = pcVar10->type;
    cVar5 = (char)pcVar3->code;
    while (cVar5 < '\0') {
      pcVar3 = pcVar3->base;
      cVar5 = (char)pcVar3->code;
    }
    g_prototype_unnamed_tag_keyword = type_keyword_text(pcVar3->code);
    return buf_00;
  }
  while (cVar9 < '\0') {
    type = type->base;
    cVar9 = (char)type->code;
  }
  if ((type->code & 0x300) == 0) {
    pcVar10 = (c1_symbol *)0x0;
  }
  else {
    pcVar10 = (type->extra).cls;
  }
  format_qualified_name(buf_00,&pcVar10->kind);
joined_r0x10484731:
  if (trailing_space != '\0') {
    format_buffer_append_char(buf_00,' ');
  }
  return buf_00;
}

