int __cdecl
format_decl_specifiers_text
          (int buf,uint bits,void *segment,uint spec_08,uint uuid,uint spec_10,uint class_flags)

{
  uint uVar1;
  char *s;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint prefix_args [6];
  
  if (buf == 0) {
    prefix_args[5] = 0x10484a4d;
    buf = format_buffer_alloc();
  }
  uVar1 = bits;
  if ((bits & 0x800) == 0) {
    if ((bits & 0x100) == 0) goto LAB_10484a73;
    prefix_args[5] = (uint)s_inline_104c0450;
  }
  else {
    prefix_args[5] = (uint)s___forceinline_104c0284;
  }
  prefix_args[3] = 0x10484a68;
  prefix_args[4] = buf;
  format_buffer_append_string(buf,(char *)prefix_args[5]);
  prefix_args[3] = 0x20;
  prefix_args[1] = 0x10484a70;
  prefix_args[2] = buf;
  format_buffer_append_char(buf,' ');
LAB_10484a73:
  if ((uVar1 & 0x200) != 0) {
    prefix_args[5] = (uint)s_virtual_104c03d0;
    prefix_args[3] = 0x10484a85;
    prefix_args[4] = buf;
    format_buffer_append_string(buf,"virtual");
    prefix_args[3] = 0x20;
    prefix_args[1] = 0x10484a8d;
    prefix_args[2] = buf;
    format_buffer_append_char(buf,' ');
  }
  if ((bits & 0x4000000) != 0) {
    prefix_args[5] = (uint)s_mutable_104c0448;
    prefix_args[3] = 0x10484aa3;
    prefix_args[4] = buf;
    format_buffer_append_string(buf,"mutable");
    prefix_args[3] = 0x20;
    prefix_args[1] = 0x10484aab;
    prefix_args[2] = buf;
    format_buffer_append_char(buf,' ');
  }
  if ((bits & 0x8000000) != 0) {
    prefix_args[5] = (uint)s_explicit_104c0460;
    prefix_args[3] = 0x10484ac2;
    prefix_args[4] = buf;
    format_buffer_append_string(buf,"explicit");
    prefix_args[3] = 0x20;
    prefix_args[1] = 0x10484aca;
    prefix_args[2] = buf;
    format_buffer_append_char(buf,' ');
  }
  if ((g_opt_Zg == '\0') && ((uVar1 & 0x400) != 0)) {
    prefix_args[5] = (uint)s_friend_104c0458;
    prefix_args[3] = 0x10484ae8;
    prefix_args[4] = buf;
    format_buffer_append_string(buf,"friend");
    prefix_args[3] = 0x20;
    prefix_args[1] = 0x10484af0;
    prefix_args[2] = buf;
    format_buffer_append_char(buf,' ');
  }
  if ((uVar1 & 0x20) == 0) {
    switch(uVar1 & 7) {
    case 0:
      s = "";
      break;
    case 1:
      s = "extern";
      break;
    case 2:
      s = "/*global*/";
      break;
    case 3:
      s = "static";
      break;
    case 4:
      s = "auto";
      break;
    case 5:
      s = "register";
      break;
    case 6:
      s = "/* really */ register";
      break;
    case 7:
      s = "typedef";
      break;
    default:
      s = "/*CLASS?*/";
    }
    prefix_args[3] = 0x10484b2e;
    prefix_args[4] = buf;
    prefix_args[5] = (uint)s;
    format_buffer_append_string(buf,s);
    prefix_args[3] = 0x20;
    prefix_args[1] = 0x10484b36;
    prefix_args[2] = buf;
    format_buffer_append_char(buf,' ');
  }
  puVar3 = &bits;
  puVar4 = prefix_args;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar2 = format_declspec_prefix
                    (buf,prefix_args[0],(void *)prefix_args[1],prefix_args[2],prefix_args[3],
                     prefix_args[4],(byte)prefix_args[5]);
  return iVar2;
}

