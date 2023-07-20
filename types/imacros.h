static inline unsigned iminor(const struct inode *inode)
{
	return MINOR(inode->i_rdev);
}
static inline unsigned imajor(const struct inode *inode)
{
	return MAJOR(inode->i_rdev);
}
