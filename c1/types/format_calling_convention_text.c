int __cdecl
format_calling_convention_text(int ctx,void *emit,c1_u16 modifier,int based,c1_type *type)

{
  ushort uVar1;
  int handle;
  char *pcVar2;
  
  (*emit)(ctx,(&g_calling_convention_names)[(byte)type->flags & 7]);
  if (g_ms_extensions == '\0') {
    return ctx;
  }
  if ((modifier & 8) != 0) {
    handle = decorate_based_text((byte)modifier,based);
    pcVar2 = format_buffer_text(handle);
    (*emit)(ctx,pcVar2);
    format_buffer_free(handle);
  }
  if (((((char)type->code < '\0') && (uVar1 = type->code & 0x8f, uVar1 != 0x80)) && (uVar1 != 0x86))
     && (((uVar1 != 0x82 && (uVar1 != 0x8a)) && ((uVar1 != 0x8e && (((byte)modifier & 7) == 3))))))
  {
    (*emit)(ctx,"__fastcall ");
  }
  return ctx;
}

