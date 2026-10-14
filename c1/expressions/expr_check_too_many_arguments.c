c1_node * __cdecl
expr_check_too_many_arguments(uint flags,c1_call_context *ctx,c1_node *item,c1_node *node)

{
  c1_type *pcVar1;
  ushort uVar2;
  byte bVar3;
  int n;
  char *pcVar4;
  int iVar5;
  
  if ((flags & 0x20) == 0) {
    if (g_ms_extensions == '\0') {
      diag_error(0xc5,0x73,ctx->name);
    }
    else {
      diag_warning(1,0x14,ctx->name);
    }
    g_call_context->flags = g_call_context->flags | 0x20;
    ctx = g_call_context;
  }
  pcVar1 = node->type;
  bVar3 = (byte)pcVar1->code;
  if ((char)bVar3 < '\0') {
    if ((bVar3 & 0x8f) == 0x86) {
      item->type = pcVar1;
      return item;
    }
    uVar2 = pcVar1->flags & 0x18;
    if ((uVar2 == 0x18) || (uVar2 == 8)) {
      if ((ctx->flags & 8) == 0) {
        iVar5 = ctx->nargs;
        pcVar4 = ctx->name;
        n = 0x17;
      }
      else {
        if ((ctx->flags & 4) == 0) goto LAB_1061df2a;
        iVar5 = ctx->nargs;
        pcVar4 = ctx->name;
        n = 0x19;
      }
      diag_warning(1,n,pcVar4,iVar5);
    }
  }
LAB_1061df2a:
  item->type = g_type_none;
  return item;
}

