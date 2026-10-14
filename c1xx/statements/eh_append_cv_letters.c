char * __thiscall eh_append_cv_letters(c1_catch_handler *type_rec,char *out)

{
  if (((byte)type_rec->cv >> 5 & 1) != 0) {
    *out = 'C';
    out = out + 1;
  }
  if (((byte)type_rec->cv >> 6 & 1) != 0) {
    *out = 'V';
    out = out + 1;
  }
  if ((char)type_rec->cv < '\0') {
    *out = 'U';
    out = out + 1;
  }
  *out = '\0';
  return out;
}

