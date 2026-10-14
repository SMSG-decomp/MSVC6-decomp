int __cdecl action_expand_alternative(char *p,char *out,char *value,char **alt)

{
  char *end;
  char *end_2;
  
  *out = '\0';
  end = action_expand_value(p + 1,out,value);
  end_2 = action_expand_value(end + 1,g_alternative_buffer,value);
  if (*out == '\0') {
    strcpy(out,g_alternative_buffer);
  }
  *alt = g_alternative_buffer;
  return (int)(end_2 + 1);
}

